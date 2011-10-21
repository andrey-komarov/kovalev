#ifndef POINT_H
#define POINT_H

#include "geom_config.h"
#include <ostream>

struct point
{
    point();
    point(const coord_t& x, const coord_t& y);

    point& operator+=(const point&);
    point& operator-=(const point&);
    point& operator*=(const coord_t&);
    point& operator/=(const coord_t&);
    coord_t operator*(const point&) const; // vector multiply

    coord_t x, y;
};

point operator+(point, const point&);
point operator-(point, const point&);

point operator*(point, const coord_t&);
point operator*(const coord_t&, point);

point operator/(point, const coord_t&);

std::ostream& operator<<(std::ostream&, const point&);

#endif // POINT_H
