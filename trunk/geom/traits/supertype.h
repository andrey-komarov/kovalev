#ifndef SUPERTYPE_H
#define SUPERTYPE_H

#include "fraction/fraction.h"

namespace geom
{
    namespace traits
    {
        template<typename T, typename K>
        struct supertype
        {};

        template<typename T>
        struct supertype<T, T>
        {
            typedef T type;
        };

        template<>
        struct supertype<double, fraction>
        {
            typedef fraction type;
        };

        template<>
        struct supertype<fraction, double>
        {
            typedef fraction type;
        };
    }
}

#endif // SUPERTYPE_H
