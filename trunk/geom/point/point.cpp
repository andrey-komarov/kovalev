#include "geom/point.h"

namespace
{
    struct compareByX_visitor : public boost::static_visitor<geom::Sign>
    {
        template<typename T, typename K>
        geom::Sign operator()(const geom::simple_point<T>& p1, const geom::simple_point<K>& p2) const
        {
            typedef typename geom::traits::supertype<T, K>::type supertype;
            return geom::utils::compare(static_cast<supertype>(p1.x), static_cast<supertype>(p2.x));
        }
    };

    struct compareByY_visitor : public boost::static_visitor<geom::Sign>
    {
        template<typename T, typename K>
        geom::Sign operator()(const geom::simple_point<T>& p1, const geom::simple_point<K>& p2) const
        {
            typedef typename geom::traits::supertype<T, K>::type supertype;
            return geom::utils::compare(static_cast<supertype>(p1.y), static_cast<supertype>(p2.y));
        }
    };

}

namespace geom
{

point::point()
{
}

point::point(double x, double y):
        data_(simple_point<double>(x, y))
{}

point::point(const fraction& x, const fraction& y):
        data_(simple_point<fraction>(x, y))
{}

geom::Sign compareByX(const point& p1, const point& p2)
{
    return boost::apply_visitor(compareByX_visitor(), p1.data_, p2.data_);
}

geom::Sign compareByY(const point& p1, const point& p2)
{
    return boost::apply_visitor(compareByY_visitor(), p1.data_, p2.data_);
}

bool point::operator<(const point& p) const
{
    geom::Sign x = compareByX(*this, p);
    if (x != geom::EQUAL)
        return x == geom::LESS;
    return compareByY(*this, p) == geom::LESS;
}

std::ostream& operator<<(std::ostream& out, const point& p)
{
    return out << p.data_;
}

}
