#include "point.h"

template<typename T>
point<T>::point(const T& x, const T& y) :
    x(x), y(y)
{}

template<typename T>
bool point<T>::operator==(const point<T>& p) const
{
    return x == p.x && y == p.y;
}

template<typename T>
bool point<T>::operator<(const point<T>& p) const
{
    if (p.x != x)
        return x < p.x;
    return y < p.y;
}
