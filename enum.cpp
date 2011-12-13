#include "geom/enum.h"

namespace geom
{

Sign negate(Sign s)
{
    return s == EQUAL ? EQUAL : s == LESS ? GREATER : LESS;
}

}
