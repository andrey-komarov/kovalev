#include "predicates.h"

int predicates::orientation(const point &a, const point &b, const point &c)
{
    // (b - a) x (c - a)
    // b - a = v1 = (b.x - a.x, b.y - a.y)
    // c - a = v2 = (c.x - a.x, c.y - a.y)
    // v1 x v2 = v1.x * v2.y - v1.y * v2.x
    // v1 x v2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)
    // v1 x v2 = b.x * c.y - a.x * c.y - b.x * a.y // + a.x * a.y
    //          -b.y * c.x + a.y * c.x + b.y * a.x // - a.y * a.x
    expansion e;
    e.add(two_product(b.x, c.y));
    e.add(two_product(-a.x, c.y));
    e.add(two_product(-b.x, a.y));
    e.add(two_product(-b.y, c.x));
    e.add(two_product(a.y, c.x));
    e.add(two_product(b.y, a.x));
    return e.sign();
}
