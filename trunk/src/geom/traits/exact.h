#ifndef EXACT_H
#define EXACT_H

#include "fraction/fraction.h"

namespace geom
{

namespace traits
{

template<typename T>
struct exact
{};

template<>
struct exact<double>
{
    typedef fraction type;
};

template<>
struct exact<fraction>
{
    typedef fraction type;
};

} // traits

} // geom
#endif // EXACT_H
