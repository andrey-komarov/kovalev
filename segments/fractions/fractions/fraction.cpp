#include "fraction.h"
fraction::fraction() : p(0), q(1) {}

fraction::fraction(int p) : p(p), q(1) {}

static const size_t MANTISS = 52;
static const size_t EXPONENT = 11;

namespace
{

const size_t BITS_IN_BYTE = 8;

std::vector<bool> binary_repsesentation(char ch)
{
    std::vector<bool> ans(BITS_IN_BYTE, 0);
    for (size_t i = 0; i < BITS_IN_BYTE; i++)
    {
        ans[i] = (ch >> i) & 1;
    }
    return ans;
}

template<typename T>
std::vector<bool> binary_repsesentation(const T& item)
{
    union
    {
        T a;
        char b[sizeof(T)];
    } bytes;
    bytes.a = item;
    std::vector<bool> ans;
    for (size_t i = 0; i < sizeof(T); i++)
    {
        std::vector<bool> now = binary_repsesentation(bytes.b[i]);
        for (size_t j = 0; j < BITS_IN_BYTE; j++)
            ans.push_back(now[j]);
    }
    return ans;
}

}

fraction::fraction(double a)
{
    if (a == 0. || a == -0.)
    {
        p = 0;
        q = 1;
        return;
    }
    std::vector<bool> repr = binary_repsesentation(a);
    int sign = repr[MANTISS + EXPONENT] ? -1 : 1;
    big_int mantiss = 1;
    for (size_t i = 0; i < MANTISS; i++)
    {
        mantiss *= 2;
        mantiss += repr[MANTISS - i - 1] ? 1 : 0;
    }
    int exponent = 0;
    for (size_t i = 0; i < EXPONENT; i++)
    {
        exponent *= 2;
        exponent += repr[MANTISS + EXPONENT - i - 1] ? 1 : 0;
    }
    exponent = exponent - ((1 << (EXPONENT - 1)) - 1) - MANTISS;
    q = 1;
    for (int i = 0; i < abs(exponent); i++)
    {
        q *= 2; // TODO: optimize
    }
    if (exponent >= 0)
    {
        p = sign * mantiss * q;
        q = 1;
    }
    else
    {
        p = sign * mantiss;
    }
    normalize();
}


fraction::fraction(const big_int& p) : p(p), q(1) {}

fraction::fraction(const big_int& p, const big_int& q) : p(p), q(q)
{
    normalize();
}

fraction::fraction(const fraction& f) : p(f.p), q(f.q) {}

fraction& fraction::operator +=(const fraction& f)
{
    big_int newq = q * f.q;
    p = p * f.q + q * f.p;
    q = newq;
    normalize();
    return *this;
}

fraction& fraction::operator -=(const fraction& f)
{
    big_int newq = q * f.q;
    p = p * f.q - q * f.p;
    q = newq;
    normalize();
    return *this;
}

fraction& fraction::operator *=(const fraction& f)
{
    p *= f.p;
    q *= f.q;
    normalize();
    return *this;
}

fraction& fraction::operator /=(const fraction& f)
{
    p *= f.q;
    q *= f.p;
    normalize();
    return *this;
}

fraction operator+(fraction a, const fraction& b)
{
    return a += b;
}

fraction operator-(fraction a, const fraction& b)
{
    return a -= b;
}

fraction operator*(fraction a, const fraction& b)
{
    return a *= b;
}

fraction operator/(fraction a, const fraction& b)
{
    return a /= b;
}

fraction operator-(fraction f)
{
    f.p = -f.p;
    return f;
}

bool fraction::operator==(const fraction& f) const
{
    return p == f.p && q == f.q;
}

bool fraction::operator<(const fraction& f) const
{
    return p * f.q - q * f.p < 0;
}

bool operator<=(const fraction& f1, const fraction& f2)
{
    return !(f2 < f1);
}


void fraction::normalize()
{
    if (q < 0)
    {
        q = -q;
        p = -p;
    }
    if (q == 0)
    {
        p = p < 0 ? -1 : 1;
    }
    else
    {
        big_int g = abs(gcd(p, q));
        p /= g;
        q /= g;
    }
}

big_int fraction::gcd(const big_int &a, const big_int &b)
{
    return b == 0 ? a : gcd(b, a % b);
}

std::ostream& operator<<(std::ostream& out, const fraction& f)
{
    if (f.q == 1)
        return out << f.p;
    return out << f.p << "/" << f.q;
}
