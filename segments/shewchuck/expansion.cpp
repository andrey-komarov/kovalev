#include "expansion.h"

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

int expansion::sign(double a)
{
    if (a == 0. || a == -0.)
        return 0;
    return a < 0. ? -1 : 1;
}

int expansion::sign() const
{
    if (values_.size() == 0)
        return 0;
    return sign(values_.back());
}

int expansion::size() const
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

void expansion::grow_expantion(double a)
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


double expansion::approximate_sum() const
{
    double res = 0.;
    for (std::size_t i = 0; i < values_.size(); i++)
    {
        res += values_[i];
    }
    return res;
}

void expansion::add(double a)
{
    grow_expantion(a);
}

void expansion::add(std::pair<double, double> p)
{
    add(p.first);
    add(p.second);
}

void expansion::add(expansion e)
{
    for (std::size_t i = 0; i < e.values_.size(); i++)
    {
        add(e.values_[i]);
    }
}

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
    std::pair<double, double> a_hi_low = split(a, (MANTISS + 1) / 2);
    std::pair<double, double> b_hi_low = split(b, (MANTISS + 1) / 2);
    double err1 = x - (a_hi_low.first * b_hi_low.first);
    double err2 = err1 - (a_hi_low.second * b_hi_low.first);
    double err3 = err2 - (a_hi_low.first * b_hi_low.second);
    double y = (a_hi_low.second * b_hi_low.second) - err3;
    return std::make_pair(x, y);
}

std::ostream& operator<<(std::ostream& out, const expansion& e)
{
    out << "[";
    for (size_t i = 0; i < e.values_.size(); i++)
    {
        out << e.values_[i] << " ";
    }
    return out << "]";
}
