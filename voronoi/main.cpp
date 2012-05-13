#include <iostream>

#include "number.h"
#include <cassert>
#include <cstdlib>
#include <cmath>

using namespace std;

template<typename T>
int sgn(const T& a)
{
    if (a == 0)
        return 0;
    return a < 0 ? - 1: 1;
}

int main()
{
    srand(time(NULL));
    int n  = 100;
    while (true)
    {
        int a = rand() % n - n / 2;
        int b = rand() % n - n / 2;
        int c = rand() % n - n / 2;
        int d = rand() % n - n / 2;
        cerr << a << " " << b << " " << c << " " << d << "\n";
        double d1 = a + sgn(b) * sqrt(abs(b));
        double d2 = c + sgn(d) * sqrt(abs(d));
        bool s1 = d1 < d2;
        cerr << d1 << " " << d2 << " " << s1 << "\n";
        number n1(a, b);
        number n2(c, d);
        bool s2 = n1 < n2;
        cerr << n1 << " " << n2 << " " << s2 << "\n";
        assert (s1 == s2);
        assert (!((n1 == n2) ^ (d1 == d2)));
        cerr << "========================\n";
    }
}
