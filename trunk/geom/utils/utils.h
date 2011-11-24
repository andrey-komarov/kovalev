#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <ostream>

#include "big_int/big_int.h"
#include "geom/enum.h"

namespace geom
{
namespace utils
{

const size_t BITS_IN_BYTE = 8;

template<typename T>
geom::Sign compare(const T& a, const T& b)
{
    if (a == b)
        return geom::EQUAL;
    return a < b ? geom::LESS : geom::GREATER;
}

std::vector<bool> binary_repsesentation(char ch);

template<typename T>
std::vector<bool> binary_repsesentation(const T& item)
{
    union
    {
        T a;
        char b[sizeof(T)];
    } bytes;
    bytes.a = item;
    std::vector<bool> ans;
    for (size_t i = 0; i < sizeof(T); i++)
    {
        std::vector<bool> now = binary_repsesentation(bytes.b[i]);
        for (size_t j = 0; j < BITS_IN_BYTE; j++)
            ans.push_back(now[j]);
    }
    return ans;
}

} // utils

} // geom
#endif // UTILS_H
