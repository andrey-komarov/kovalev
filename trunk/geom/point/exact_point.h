#ifndef EXACT_POINT_H
#define EXACT_POINT_H


#include "geom/errors.h"
#include <ostream>

namespace geom
{

struct exact_point
{

};

std::ostream& operator<<(std::ostream&, const exact_point&);

}
#endif // EXACT_POINT_H
