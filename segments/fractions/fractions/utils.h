#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <ostream>

#include "fraction.h"
#include "big_int.h"

//template<typename T>
//std::ostream& operator<<(std::ostream& out, const std::vector<T>& v);

namespace utils
{
const size_t BITS_IN_BYTE = 8;

std::vector<bool> binary_repsesentation(char ch);

fraction make_fraction(double);

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

template<typename T>
int signum(const T& a)
{
    if (a == 0)
        return 0;
    return a < 0 ? -1 : 1;
}

};


template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v)
{
    out << "[";
    for (size_t i = 0; i + 1 < v.size(); i++)
    {
        out << v[i] << ", ";
    }
    return out << v.back() << "]";
}

#endif // UTILS_H
