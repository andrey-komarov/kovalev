#ifndef POINT_H
#define POINT_H

#include "geom/errors.h"
#include "geom/utils.h"
#include "geom/enum.h"
#include "simple_point.h"
#include "fraction/fraction.h"
#include "geom/traits/supertype.h"

#include <ostream>

#include <boost/variant.hpp>

namespace geom
{

struct point
{
    point();
    point(double, double);
    point(const fraction&, const fraction&);

    bool operator<(const point&) const;
private:
    boost::variant<geom::simple_point<double>, geom::simple_point<fraction> > data_;
    friend geom::Sign compareByX(const point&, const point&);
    friend geom::Sign compareByY(const point&, const point&);
    friend std::ostream& operator<<(std::ostream&, const point&);
};

geom::Sign compareByX(const point&, const point&);
geom::Sign compareByY(const point&, const point&);
std::ostream& operator<<(std::ostream&, const point&);

}
#endif // POINT_H
