#include "geom/enum.h"

namespace geom
{
    Sign negate(Sign s)
    {
        if (s == ZERO)
            return ZERO;
        return s == NEGATIVE ? POSITIVE : NEGATIVE;
    }
}
