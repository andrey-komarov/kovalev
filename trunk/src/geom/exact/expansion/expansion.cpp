#include "expansion.h"

namespace geom
{

expansion::expansion(double a)
{
    values_.push_back(a);
}

expansion::expansion(const expansion& e) :
    values_(e.values_)
{}

expansion::expansion(const std::vector<double>& v) :
    values_(v)
{}

expansion& expansion::operator=(const expansion& e)
{
    this->values_ = e.values_;
    return *this;
}

void expansion::swap(expansion& e)
{
    std::swap(values_, e.values_);
}

geom::Sign expansion::sign() const
{
    if (values_.size() == 0)
        return geom::ZERO;
    return geom::utils::signum(values_.back());
}

size_t expansion::size() const
{
    return values_.size();
}

std::pair<double, double> expansion::sum_two(double a, double b)
{
    double x = a + b;
    double b_virtual = x - a;
    double a_virtual = x - b_virtual;
    double b_roundoff = b - b_virtual;
    double a_roundoff = a - a_virtual;
    double y = a_roundoff + b_roundoff;
    return std::make_pair(x, y);
}

void expansion::grow_expansion(double a)
{
    std::size_t m = size();
    std::vector<double> q;
    std::vector<double> h;
    q.push_back(a);
    for (std::size_t i = 1; i <= m; i++)
    {
        std::pair<double, double> p = sum_two(q[i - 1], values_[i - 1]);
        q.push_back(p.first);
        if (p.second != 0.0)
            h.push_back(p.second);
    }
    if (q[m] != 0.0)
        h.push_back(q[m]);
    values_ = h;
}

bool expansion::is_double() const
{   return values_.size() <= 1;}

double expansion::approximate_sum() const
{
    double res = 0.;
    for (std::size_t i = 0; i < values_.size(); i++)
    {
        res += values_[i];
    }
    return res;
}

expansion& expansion::operator+=(double a)
{
    grow_expansion(a);
    return *this;
}

expansion& expansion::operator+=(const std::pair<double, double>& p)
{
    grow_expansion(p.first);
    grow_expansion(p.second);
    return *this;
}

expansion& expansion::operator+=(const expansion& e)
{
    for (std::size_t i = 0; i < e.values_.size(); i++)
    {
        operator+=(e.values_[i]);
    }
    return *this;
}

expansion& expansion::operator*=(double a)
{
    expansion res;
    for (std::vector<double>::const_iterator it = values_.begin(); it != values_.end(); it++)
        res += two_product(*it, a);
    swap(res);
    return *this;
}

expansion& expansion::operator*=(const expansion& e)
{
    expansion accumulator(0);
    for (std::vector<double>::const_iterator it = e.values_.begin(); it != e.values_.end(); it++)
        accumulator += *this * *it;
    swap(accumulator);
    return *this;
}

expansion operator-(expansion e)
{
    for (std::vector<double>::iterator it = e.values_.begin(); it != e.values_.end(); it++)
        *it = -*it;
    return e;
}

bool expansion::operator==(const expansion& e) const
{
    if (values_.size() != e.values_.size())
        return false;
    for (
            std::vector<double>::const_iterator it1 = values_.begin(),
                                                it2 = e.values_.begin();
            it1 != values_.end() && it2 != e.values_.end();
            it1++, it2++
    )
    {
       if (*it1 != *it2)
            return false;
    }
    return true;
}

bool expansion::operator<(const expansion& e) const
{
    std::vector<double>::const_reverse_iterator it1, it2;
    for (
            it1 = values_.rbegin(), it2 = e.values_.rbegin();
            it1 != values_.rend() && it2 != e.values_.rend();
            it1++, it2++
    )
    {
        if (*it1 != *it2)
            return *it1 < *it2;
    }
    if (it1 != values_.rend() && *it1 < 0)
        return true;
    if (it2 != e.values_.rend() && *it2 > 0)
        return true;
    return false;
}

expansion& operator-=(expansion& e1, const expansion& e2)
{    return e1 += -e2;}

expansion operator-(expansion e1, const expansion& e2)
{   return e1 -= e2;}

expansion operator+(expansion e1, const expansion& e2)
{   return e1 += e2;}

expansion operator*(expansion e1, double d)
{   return e1 *= d;}

expansion operator*(expansion e1, const expansion& e2)
{   return e1 *= e2;}

bool operator!=(const expansion& e1, const expansion& e2)
{   return !(e1 == e2);}

std::pair<double, double> split(double a, int s)
{
    double c = ((1 << s) + 1) * a;
    double a_big = c - a;
    double a_hi = c - a_big;
    double a_low = a - a_hi;
    return std::make_pair(a_hi, a_low);
}

std::pair<double, double> two_product(double a, double b)
{
    double x = a * b;
    std::pair<double, double> a_hi_low = split(a, (geom::MANTISS + 1) / 2);
    std::pair<double, double> b_hi_low = split(b, (geom::MANTISS + 1) / 2);
    double err1 = x - (a_hi_low.first * b_hi_low.first);
    double err2 = err1 - (a_hi_low.second * b_hi_low.first);
    double err3 = err2 - (a_hi_low.first * b_hi_low.second);
    double y = (a_hi_low.second * b_hi_low.second) - err3;
    return std::make_pair(x, y);
}

std::ostream& operator<<(std::ostream& out, const geom::expansion& e)
{
    out << "[";
    for (size_t i = 0; i < e.values_.size(); i++)
    {
        out << e.values_[i] << " ";
    }
    return out << "]";
}

}
