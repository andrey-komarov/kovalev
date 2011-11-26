#include "geom/predicates.h"
#include "geom/traits/exact.h"

namespace
{
    struct subtract_point_visitor : public boost::static_visitor<geom::point>
    {
        template<typename T, typename K>
        geom::point operator()(const geom::simple_point<T>& p1, const geom::simple_point<K>& p2) const
        {
            typedef typename geom::traits::exact<T>::type exact1;
            typedef typename geom::traits::exact<K>::type exact2;
            typedef typename geom::traits::supertype<exact1, exact2>::type supertype;

            supertype x = static_cast<supertype>(p2.x) - static_cast<supertype>(p1.x);
            supertype y = static_cast<supertype>(p2.y) - static_cast<supertype>(p1.y);
            return geom::point(x, y);
        }
    };

    struct vector_multiply_signum_visitor : public boost::static_visitor<geom::Sign>
    {
        template<typename T, typename K>
        geom::Sign operator()(const geom::simple_point<T>& p1, const geom::simple_point<K>& p2) const
        {
            typedef typename geom::traits::exact<T>::type exact1;
            typedef typename geom::traits::exact<K>::type exact2;
            typedef typename geom::traits::supertype<exact1, exact2>::type supertype;
            supertype vmul = static_cast<supertype>(p1.x) * static_cast<supertype>(p2.y) -
                             static_cast<supertype>(p1.y) * static_cast<supertype>(p2.x);
            return geom::utils::signum(vmul);
        }
    };
}

namespace geom
{

namespace predicates
{

geom::Sign orientation(const geom::point& a, const geom::point& b, const geom::point& c)
{
    return orientation(a, b, a, c);
}

Sign orientation(const point& a, const point& b, const point& c, const point& d)
{
    point ab = boost::apply_visitor(subtract_point_visitor(), a.get(), b.get());
    point cd = boost::apply_visitor(subtract_point_visitor(), c.get(), d.get());
    Sign result = boost::apply_visitor(vector_multiply_signum_visitor(), ab.get(), cd.get());
    return result;
}

} // predicates

} // geom
