#ifndef FRACTION_H
#define FRACTION_H

#include "big_int.h"
#include <ostream>

struct fraction
{
    fraction(int = 0);
    fraction(const big_int& = 0);
    fraction(const big_int& p, const big_int& q);
    fraction(const fraction&);

    fraction& operator+=(const fraction&);
    fraction& operator-=(const fraction&);
    fraction& operator*=(const fraction&);
    fraction& operator/=(const fraction&);

    bool operator==(const fraction&) const;
    bool operator<(const fraction&) const;
private:
    static big_int gcd(const big_int& a, const big_int& b);
    void normalize();

    big_int p, q;

    friend fraction operator-(fraction);
    friend std::ostream& operator<<(std::ostream& out, fraction f);
};

bool operator<=(const fraction& f1, const fraction& f2);

fraction operator+(fraction a, const fraction& b);
fraction operator-(fraction a, const fraction& b);
fraction operator*(fraction a, const fraction& b);
fraction operator/(fraction a, const fraction& b);

#endif // FRACTION_H
