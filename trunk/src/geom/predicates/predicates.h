#ifndef PREDICATES_H
#define PREDICATES_H

#include "geom/enum.h"
#include "geom/point.h"
#include "geom/exact/expansion/expansion.h"

namespace geom
{

namespace predicates
{

// sign([ab] x [ac])
geom::Sign orientation(const geom::point& a, const geom::point& b, const geom::point& c);

// sign([ab] x [cd])
//geom::Sign orientation(const geom::point& a, const geom::point& b, const geom::point& c, const geom::point& d);

} // predicates

} // geom

#endif // PREDICATES_H
