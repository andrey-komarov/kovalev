#include "segment.h"

segment::segment() {}

segment::segment(const point& a, const point& b) : a(a), b(b) {}

bool bound_boxes_intersect(const segment& s1, const segment& s2)
{
    bool c1 = std::max(std::min(s1.a.x, s1.b.x), std::min(s2.a.x, s2.b.x)) <= std::min(std::max(s1.a.x, s1.b.x), std::max(s2.a.x, s2.b.x));
    bool c2 = std::max(std::min(s1.a.y, s1.b.y), std::min(s2.a.y, s2.b.y)) <= std::min(std::max(s1.a.y, s1.b.y), std::max(s2.a.y, s2.b.y));
    return c1 && c2;
}

bool intersects(const segment& s1, const segment& s2)
{
    int o1 = predicates::orientation(s1.a, s1.b, s2.a) * predicates::orientation(s1.a, s1.b, s2.b);
    int o2 = predicates::orientation(s2.a, s2.b, s1.a) * predicates::orientation(s2.a, s2.b, s1.b);
    if (o1 > 0 || o2 > 0)
        return false;
    return bound_boxes_intersect(s1, s2);
}

bool same_line(const segment& s1, const segment& s2)
{
    if (predicates::orientation(s1.a, s1.b, s2.a) == 0 && predicates::orientation(s1.a, s1.b, s2.b) == 0)
        return true;
    return false;
}
