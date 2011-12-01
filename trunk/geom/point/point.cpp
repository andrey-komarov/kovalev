#include "geom/point.h"

namespace
{
    struct compareByX_visitor : public boost::static_visitor<geom::Sign>
    {
        geom::Sign operator()(const geom::simple_point<double>& p1, const geom::simple_point<double>& p2) const
        {
            return geom::utils::compare(p1.x, p2.x);
        }

        template<typename T, typename K>
        geom::Sign operator()(const T&, const K&) const
        {
            throw geom::errors::not_implemented_yet();
        }
    };

    struct compareByY_visitor : public boost::static_visitor<geom::Sign>
    {
        geom::Sign operator()(const geom::simple_point<double>& p1, const geom::simple_point<double>& p2) const
        {
            return geom::utils::compare(p1.y, p2.y);
        }

        template<typename T, typename K>
        geom::Sign operator()(const T&, const K&) const
        {
            throw geom::errors::not_implemented_yet();
        }
    };

}

namespace geom
{

point::point() :
        data_(simple_point<double>(0, 0))
{}

point::point(double x, double y):
        data_(simple_point<double>(x, y))
{}

geom::Sign compareByX(const point& p1, const point& p2)
{
    return boost::apply_visitor(compareByX_visitor(), p1.data_, p2.data_);
}

geom::Sign compareByY(const point& p1, const point& p2)
{
    return boost::apply_visitor(compareByY_visitor(), p1.data_, p2.data_);
}

const boost::variant<geom::simple_point<double>, geom::exact_point >& point::get() const
{
    return data_;
}

bool point::operator<(const point& p) const
{
    geom::Sign x = compareByX(*this, p);
    if (x != geom::EQUAL)
        return x == geom::LESS;
    return compareByY(*this, p) == geom::LESS;
}

bool point::operator==(const point& p) const
{
    return compareByX(p, *this) == EQUAL && compareByY(p, *this) == EQUAL;
}

bool operator>(const geom::point& p1, const geom::point& p2)
{
    return p2 < p1;
}

bool operator>=(const geom::point& p1, const geom::point& p2)
{
    return !(p1 < p2);
}

bool operator<=(const geom::point& p1, const geom::point& p2)
{
    return !(p2 < p1);
}

bool operator!=(const geom::point& p1, const geom::point& p2)
{
    return !(p1 == p2);
}

std::ostream& operator<<(std::ostream& out, const point& p)
{
    return out << p.data_;
}

}
