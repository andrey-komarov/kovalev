#ifndef POINT_H
#define POINT_H

#include "geom/errors.h"
#include "geom/utils.h"
#include "geom/enum.h"
#include "simple_point.h"
#include "exact_point.h"
#include "fraction/fraction.h"
//#include "geom/traits/supertype.h"

#include <ostream>

#include <boost/variant.hpp>

namespace geom
{

struct point
{
    point();
    point(double, double);
    point(const exact_point&);

    bool operator<(const point&) const;
    bool operator==(const point&) const;

    const boost::variant<geom::simple_point<double>, exact_point>& get() const;

    void swap(point&);
private:
    boost::variant<geom::simple_point<double>, exact_point> data_;
    friend geom::Sign compareByX(const point&, const point&);
    friend geom::Sign compareByY(const point&, const point&);
    friend std::ostream& operator<<(std::ostream&, const point&);
};

bool operator>(const point&, const point&);
bool operator>=(const point&, const point&);
bool operator<=(const point&, const point&);
bool operator!=(const point&, const point&);

geom::Sign compareByX(const point&, const point&);
geom::Sign compareByY(const point&, const point&);
std::ostream& operator<<(std::ostream&, const point&);
}

#endif // POINT_H
