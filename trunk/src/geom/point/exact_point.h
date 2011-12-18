#ifndef EXACT_POINT_H
#define EXACT_POINT_H

#include "geom/enum.h"
#include "geom/errors.h"
#include "geom/point/simple_point.h"
#include "geom/exact/expansion/expansion.h"
#include <ostream>
#include <utility>

namespace geom
{

struct exact_point
{
    exact_point(const expansion& xp, const expansion& xq, const expansion& yp, const expansion& yq);

    bool is_double() const;
    simple_point<double> approximate() const;

    std::pair<expansion, expansion> x, y;

    friend std::ostream& operator<<(std::ostream&, const exact_point&);
};

namespace utils
{
Sign compare(const std::pair<expansion, expansion>&, const std::pair<expansion, expansion>&);
Sign compare(const std::pair<expansion, expansion>&, double);
Sign compare(double, const std::pair<expansion, expansion>&);
}

std::ostream& operator<<(std::ostream&, const exact_point&);

}
#endif // EXACT_POINT_H
