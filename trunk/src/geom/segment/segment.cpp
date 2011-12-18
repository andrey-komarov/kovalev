#include "geom/segment.h"

namespace
{

template<typename T>
bool in_order(const T& a, const T& b, const T& c, geom::Sign (*comp)(const T&, const T&))
{
    return (comp(a, b) != geom::GREATER && comp(b, c) != geom::GREATER)
            || (comp(a, b) != geom::LESS && comp(b, c) != geom::LESS);
}

bool check_bbox_intersection_(const geom::segment& s1, const geom::segment& s2, geom::Sign (*comp)(const geom::point&, const geom::point&))
{
    return in_order(s1.a, s2.a, s1.b, comp) || in_order(s1.a, s2.b, s1.a, comp) || in_order(s2.a, s1.a, s2.b, comp) || in_order(s2.a, s1.b, s2.b, comp);
}

bool check_bbox_intersection(const geom::segment& s1, const geom::segment& s2)
{
    return check_bbox_intersection_(s1, s2, geom::compareByX)
        && check_bbox_intersection_(s1, s2, geom::compareByY);
}

}

namespace geom
{

segment::segment(const geom::point &a, const geom::point &b) :
        a(a), b(b)
{}

std::ostream& operator<<(std::ostream& out, const segment& s)
{
    return out << "[" << s.a << "; " << s.b << "]";
}

bool on_same_line(const geom::segment& s1, const geom::segment& s2)
{
    return geom::predicates::orientation(s1.a, s1.b, s2.a) == geom::COLLINEAR
            && geom::predicates::orientation(s1.a, s1.b, s2.b) == geom::COLLINEAR;
}

bool parallel(const geom::segment& s1, const geom::segment& s2)
{
    return predicates::orientation(s1.a, s1.b, s2.a) == COLLINEAR
        && predicates::orientation(s1.a, s1.b, s2.b) == COLLINEAR;
}

bool intersects(const geom::segment& s1, const geom::segment& s2)
{
    if (!check_bbox_intersection(s1, s2))
        return false;
    if (!parallel(s1, s2))
    {
        geom::Sign p1 = predicates::orientation(s1.a, s1.b, s2.a);
        geom::Sign p2 = predicates::orientation(s1.a, s1.b, s2.b);
        if (p1 == geom::LEFT_TURN && p2 == geom::LEFT_TURN)
            return false;
        if (p1 == geom::RIGHT_TURN && p2 == geom::RIGHT_TURN)
            return false;

        p1 = predicates::orientation(s2.a, s2.b, s1.a);
        p2 = predicates::orientation(s2.a, s2.b, s1.b);
        if (p1 == geom::LEFT_TURN && p2 == geom::LEFT_TURN)
            return false;
        if (p1 == geom::RIGHT_TURN && p2 == geom::RIGHT_TURN)
            return false;
        return true;
    }
    return on_same_line(s1, s2);
}

point intersect(const geom::segment& s1, const geom::segment& s2)
{
    // TODO: Не нравится!
    const simple_point<double>& s1a = boost::get<simple_point<double> >(s1.a.get());
    const simple_point<double>& s1b = boost::get<simple_point<double> >(s1.b.get());
    const simple_point<double>& s2a = boost::get<simple_point<double> >(s2.a.get());
    const simple_point<double>& s2b = boost::get<simple_point<double> >(s2.b.get());

    // x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1)
    // y = (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1)
    // a = y1 - y2
    // b = x2 - x1
    // c = -a * x1 - b * y1 = x1*y2 - x2*y1
    // bc = (x2-x1) * (x1y2 - x2y1) =
    expansion a1 = expansion(s1a.y) - s1b.y;
    expansion b1 = expansion(s1b.x) - s1a.x;
    expansion c1 = a1 * (-s1a.x) + b1 * (-s1a.y);

    expansion a2 = expansion(s2a.y) - s2b.y;
    expansion b2 = expansion(s2b.x) - s2a.x;
    expansion c2 = a2 * (-s2a.x) + b2 * (-s2a.y);

    expansion xp = b1 * c2 - b2 * c1;
    expansion q = a1 * b2 - a2 * b1;
    expansion yp = c1 * a2 - c2 * a1;
    return point(exact_point(xp, q, yp, q));
}

}
