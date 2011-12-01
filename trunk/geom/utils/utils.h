#ifndef UTILS_H
#define UTILS_H

#include "geom/enum.h"

namespace geom
{

namespace utils
{

template<typename T>
geom::Sign compare(const T& a, const T& b)
{
    if (a == b)
        return geom::EQUAL;
    return a < b ? geom::LESS : geom::GREATER;
}

template<typename T>
geom::Sign signum(const T& a)
{
    static const T zero(0);
    if (a == zero)
        return geom::ZERO;
    return a < zero ? geom::NEGATIVE : geom::POSITIVE;
}

} // utils

} // geom
#endif // UTILS_H
