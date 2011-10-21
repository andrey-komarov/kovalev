#include "point.h"

point::point(): x(0), y(0) {}

point::point(const coord_t& x, const coord_t& y): x(x), y(y) {}

point& point::operator+=(const point& p)
{
    x += p.x;
    y += p.y;
    return *this;
}

point& point::operator-=(const point& p)
{
    x -= p.x;
    y -= p.y;
    return *this;
}

point& point::operator*=(const coord_t& a)
{
    x *= a;
    y *= a;
    return *this;
}

point& point::operator/=(const coord_t& a)
{
    x /= a;
    y /= a;
    return *this;
}

point operator+(point p1, const point& p2)
{    return p1 += p2;}

point operator-(point p1, const point& p2)
{    return p1 -= p2;}

coord_t point::operator*(const point& p) const
{    return x * p.y - y * p.x;}

point operator*(const coord_t& a, point p)
{    return p *= a;}

point operator*(point p, const coord_t& a)
{    return p *= a;}

point operator/(point p, const coord_t& a)
{    return p /= a;}

std::ostream& operator<<(std::ostream& out, const point& p)
{
    return out << "(" << p.x << ", " << p.y << ")";
}
