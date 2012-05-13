#ifndef NUMBER_H
#define NUMBER_H

#include <ostream>

#include <gmpxx.h>

struct number
{
    number(const mpq_class& a, const mpq_class& b = 0);
    bool operator<(const number& n) const;
    bool operator==(const number& n) const;
private:
    mpq_class a, b; // a + √b

    friend std::ostream& operator<<(std::ostream& out, const number& n);
    friend int cmp(const number& n1, const number& n2);
};

std::ostream& operator<<(std::ostream& out, const number& n);
int cmp(const number& n1, const number& n2);

#endif // NUMBER_H
