#ifndef ENUM_H
#define ENUM_H

namespace geom
{
    enum Sign
    {
        NEGATIVE = -1, ZERO = 0, POSITIVE = 1,
        LESS = -1, EQUAL = 0, GREATER = 1,
        RIGHT_TURN = -1, COLLINEAR = 0, LEFT_TURN = 1
    };
}

#endif // ENUM_H
