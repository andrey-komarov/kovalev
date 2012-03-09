#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Hello
#include <boost/test/unit_test.hpp>

#include "orientation.h"
#include "segment.h"

double getdouble(unsigned long long sign, unsigned long long exp, unsigned long long mant)
{
    union
    {
        double d;
        unsigned long long b;
    } res;
    res.b = (sign << 63) + (exp << 52) + mant;
    return res.d;
}


const int mult = 128;
const double meps = std::numeric_limits<double>::epsilon();

const segment s(point(-100.0, -100.0), point(100.0, 100.0));
const segment s2(point(getdouble(1, 1000, 0), 0), point(getdouble(1, 999, 0), 0));
const std::vector<std::pair<std::pair<segment, point>, Sign>> tests =
{
	{{s, point(1.0, 2.0)}, LEFT},
	{{s, point(100.0, 200.0)}, LEFT},
	{{s, point(0.0, 0.0 + 1E-10)}, LEFT},
	{{s, point(0.0, 32 * meps)}, LEFT},
	{{s, point(0.0, -32 * meps)}, RIGHT},
	{{s, point(0.0, 128 * meps)}, LEFT},
	{{s, point(0.0, getdouble(0, 1000, 1))}, LEFT},
	{{s2, point(0, 0)}, EQUAL},
	{{s2, point(getdouble(0, 1000, 1), 0)}, EQUAL},
	{{s2, point(getdouble(0, 1000, 1), getdouble(0, -1000, 0))}, RIGHT},
	{{s2, point(getdouble(0, 1000, 1), getdouble(1, -1999, 0))}, LEFT},
	{{segment(point(3.0, 5.0), point(-3.0, -5.0)), point(3.0 * (1LL << 52), 5.0 * (1LL << 52))}, EQUAL} // test from the presentation
};

void debug(segment s, point p, Sign expectedAns, Sign ans)
{
    if (expectedAns == ans)
        return;
    std::cerr << s << " " << p << " " << expectedAns << " got " << ans << std::endl;
}

/*
BOOST_AUTO_TEST_CASE( simple_cases )
{
    std::cerr << "Simple:" << std::endl;
    for (auto i = tests.begin(); i != tests.end(); ++i)
    {
        auto test = *i;
        Sign res = orientationSimple(test.first.first, test.first.second);
        debug(test.first.first, test.first.second, test.second, res);
        BOOST_CHECK_EQUAL(res, test.second);
    }
}

BOOST_AUTO_TEST_CASE( epsilon_cases )
{
    std::cerr << "Epsilon:" << std::endl;
    for (auto i = tests.begin(); i != tests.end(); ++i)
    {
        auto test = *i;
        Orientation res = orientationEpsilon(test.first.first, test.first.second);
        debug(test.first.first, test.first.second, test.second, res);
        BOOST_CHECK_EQUAL(res, test.second);
    }
}


BOOST_AUTO_TEST_CASE( interval_cases )
{
    std::cerr << "Interval:" << std::endl;
    for (auto i = tests.begin(); i != tests.end(); ++i)
    {
        auto test = *i;
        Orientation res = orientationInterval(test.first.first, test.first.second);
        debug(test.first.first, test.first.second, test.second, res);
        BOOST_CHECK_EQUAL(res, test.second);
    }
}

BOOST_AUTO_TEST_CASE( adaptive_cases )
{
    std::cerr << "Adaptive:" << std::endl;
    for (auto i = tests.begin(); i != tests.end(); ++i)
    {
        auto test = *i;
        Orientation res = orientationAdaptive(test.first.first, test.first.second);
        debug(test.first.first, test.first.second, test.second, res);
        BOOST_CHECK_EQUAL(res, test.second);
    }
}

*/
BOOST_AUTO_TEST_CASE( complete_cases)
{
    std::cerr << "Complete test:" << std::endl;
    for (auto i = tests.begin(); i != tests.end(); ++i)
    {
        auto test = *i;
        Sign res = orientation(test.first.first, test.first.second);
        debug(test.first.first, test.first.second, test.second, res);
        BOOST_CHECK_EQUAL(res, test.second);
    }
}
/*
int main()
{
    using std::cout;
    cout << orientationEpsilon(Segment(Point(0.0, 0.0), Point(4.0, 4.0)), Point(3.0, 1.0));
    return 0;
}
*/
