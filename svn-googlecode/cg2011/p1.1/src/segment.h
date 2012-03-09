#ifndef segmentH
#define segmentH

#include "point.h"
#include <ostream>

struct segment
{
	segment();
	segment(const point&, const point&);
	point a, b;
};

std::ostream& operator<<(std::ostream&, const segment&);

#endif
