#ifndef ENUM_H
#define ENUM_H

enum Sign
{
	NEGATIVE = -1, ZERO = 0, POSITIVE = 1,
	LESS = -1, EQUAL = 0, GREATER = 1,
	RIGHT_TURN = -1, COLLINEAR = 0, LEFT_TURN = 1,
	RIGHT = -1, LEFT = 1
};
Sign negate(Sign s);

#endif // ENUM_H
