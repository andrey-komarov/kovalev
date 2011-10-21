#ifndef POINT_H
#define POINT_H

#include <ostream>

struct point
{
    point();
    point(double x, double y);

    double x, y;
};

std::ostream& operator<<(std::ostream&, const point&);

#endif // POINT_H
