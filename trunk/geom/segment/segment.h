#ifndef SEGMENT_H
#define SEGMENT_H

#include "geom/point.h"
#include "geom/errors.h"
#include "geom/predicates.h"

#include <ostream>

namespace geom
{

struct segment
{
    segment(const geom::point&, const geom::point&);

    geom::point a, b;
};

std::ostream& operator<<(std::ostream&, const segment&);

bool parallel(const geom::segment&, const geom::segment&);
bool on_same_line(const geom::segment&, const geom::segment&);
bool intersects(const geom::segment&, const geom::segment&);

}

#endif // SEGMENT_H
