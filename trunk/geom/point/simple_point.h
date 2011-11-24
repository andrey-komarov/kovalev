#ifndef SIMPLE_POINT_H
#define SIMPLE_POINT_H

#include <ostream>

namespace geom
{

template<typename T>
struct simple_point
{
    T x, y;

    simple_point():
            x(), y()
    {}

    simple_point(const T& x, const T& y):
            x(x), y(y)
    {}
};

template<typename T>
std::ostream& operator<<(std::ostream& out, const simple_point<T>& p)
{
    return out << "(" << p.x << ", " << p.y << ")";
}

}

#endif // SIMPLE_POINT_H
