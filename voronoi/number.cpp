#include "number.h"

number::number(const mpq_class &a, const mpq_class &b) :
    a(a), b(b)
{}

int cmp(const number& n1, const number& n2)
{
    int s1 = cmp(n1.a, n2.a);
    int s2 = cmp(n2.b, n1.b);
    if (s1 != s2)
        return s1 < s2 ? -1 : 1;
    if (s1 == 0)
        return 0;
    int rev = s1;
    mpq_class tmp = (n1.a - n2.a) * (n1.a - n2.a) - abs(n2.b) - abs(n1.b);
    s1 = sgn(tmp);
    s2 = -sgn(n1.b) * sgn(n2.b);
    if (s1 != s2)
        return (s1 < s2 ? -1 : 1) * rev;
    rev *= (s1 == -1) ? -1 : 1;
    return cmp(tmp * tmp, abs(4 * n1.b * n2.b)) * rev;
}

bool number::operator<(const number& n) const
{
    return cmp(*this, n) == -1;
}

bool number::operator==(const number& n) const
{
    return cmp(*this, n) == 0;
}

std::ostream& operator<<(std::ostream& out, const number& n)
{
    return out << "[" << n.a << " " << (sgn(n.b) == -1 ? "-" : "+") << " √" << abs(n.b) << "]";
}
