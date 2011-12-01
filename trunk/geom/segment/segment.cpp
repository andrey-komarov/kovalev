#include "geom/segment.h"

#include <iostream>
using std::cerr;

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
    }
    else if (!on_same_line(s1, s2))
        return false;
    if (!check_bbox_intersection(s1, s2))
        return false;
    return true;
}

}
