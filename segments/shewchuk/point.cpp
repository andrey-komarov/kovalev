#include "point.h"

point::point(): x(0), y(0) {}

point::point(double x, double y): x(x), y(y) {}

std::ostream& operator<<(std::ostream& out, const point& p)
{
    return out << "(" << p.x << ", " << p.y << ")";
}
