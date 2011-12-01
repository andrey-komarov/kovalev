#include "geom/predicates.h"
#include "geom/traits/exact.h"
namespace geom
{

namespace predicates
{

geom::Sign orientation(const geom::point &a, const geom::point &b, const geom::point &c)
{
//      Ваш хвалёный apply_visitor не умеет три аргумента!!!
//    return boost::apply_visitor(orientation_visitor(), a.get(), b.get(), c.get());

    // TODO: Мне не нравится
    const geom::simple_point<double>& p1 = boost::get<geom::simple_point<double> >(a.get());
    const geom::simple_point<double>& p2 = boost::get<geom::simple_point<double> >(b.get());
    const geom::simple_point<double>& p3 = boost::get<geom::simple_point<double> >(c.get());
    expansion e;
    e.add(two_product(p2.x, p3.y));
    e.add(two_product(-p1.x, p3.y));
    e.add(two_product(-p2.x, p1.y));
    e.add(two_product(-p2.y, p3.x));
    e.add(two_product(p1.y, p3.x));
    e.add(two_product(p2.y, p1.x));
    return e.sign();

}

} // predicates

} // geom
