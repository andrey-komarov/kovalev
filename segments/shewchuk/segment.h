#ifndef SEGMENT_H
#define SEGMENT_H

#include "point.h"
#include "predicates.h"
#include <ostream>
#include <algorithm>

struct segment
{
    segment();
    segment(const point&, const point&);

    point a, b;
};

bool intersects(const segment&, const segment&);

bool parallel(const segment&, const segment&);

bool same_line(const segment&, const segment&);

std::ostream& operator<<(std::ostream&, const segment&);

#endif // SEGMENT_H
