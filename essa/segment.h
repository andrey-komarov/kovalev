#ifndef segmentH
#define segmentH

#include "point.h"

struct segment
{
	segment();
	segment(const point&, const point&);
	point a, b;
};

#endif
