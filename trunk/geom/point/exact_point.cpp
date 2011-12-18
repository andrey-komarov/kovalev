#include "exact_point.h"

namespace geom
{

exact_point::exact_point(const expansion &xp, const expansion &xq, const expansion &yp, const expansion &yq) :
    x(xp, xq), y(yp, yq)
{}

bool exact_point::is_double() const
{
    double x_res = x.first.approximate_sum() / x.second.approximate_sum();
    if (x.second * x_res != x.first)
        return false;
    double y_res = y.first.approximate_sum() / y.second.approximate_sum();
    if (y.second * y_res != y.first)
        return false;
    DEBUG("Success! Point " << *this << " was optimized to" << simple_point<double>(x_res, y_res) << "!!");
    return true;
}

simple_point<double> exact_point::approximate() const
{
    return simple_point<double>(
            x.first.approximate_sum() / x.second.approximate_sum(),
            y.first.approximate_sum() / y.second.approximate_sum());
}

std::ostream& operator<<(std::ostream& out, const geom::exact_point& p)
{
    return out <<
            "(~" <<
            p.x.first.approximate_sum() / p.x.second.approximate_sum() <<
            ", ~" <<
            p.y.first.approximate_sum() / p.y.second.approximate_sum() <<
            ")";
}

namespace utils
{
Sign compare(const std::pair<expansion, expansion>& p1, const std::pair<expansion, expansion>& p2)
{
    DEBUG("^_^ Comparing " << p1.first << "/" << p1.second << " and " << p2.first << "/" << p2.second << "\n");
    Sign res = compare(p1.first * p2.second, p1.second * p2.first);
    if (signum(p1.second) * signum(p2.second) == NEGATIVE)
        return negate(res);
    else
        return res;
}

Sign compare(const std::pair<expansion, expansion>& p1, double p2)
{
    DEBUG("^_^ Comparing " << p1.first << "/" << p1.second << " and " << p2 << "\n");
    Sign res = compare(p1.first, p1.second * p2);
    if (signum(p1.second) == NEGATIVE)
        return negate(res);
    else
        return res;
}

Sign compare(double p1, const std::pair<expansion, expansion>& p2)
{
    return negate(compare(p2, p1));
}

} // utils

} // geom

