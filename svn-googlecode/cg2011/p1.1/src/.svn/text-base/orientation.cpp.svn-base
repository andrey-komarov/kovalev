#include "orientation.h"

#include "essa.h"
Sign orientation_essa(const segment& s, const point& p)
{
	double a[12];
	a[0] = two_product(s.b.x, p.y, a[1]);
	a[2] = two_product(s.a.y, p.x, a[3]);
	a[4] = two_product(s.a.x, s.b.y, a[5]);
	a[6] = two_product(s.a.x, -p.y, a[7]);
	a[8] = two_product(s.b.y, -p.x, a[9]);
	a[10] = two_product(s.a.y, -s.b.x, a[11]);
	return signum<12>(a);
}

#include <limits>
#include <cmath>
const double meps = 8 * std::numeric_limits<double>::epsilon();
Sign orientation_epsilon(const segment& s, const point& p)
{
	double s1 = (s.b.x - s.a.x) * (p.y - s.a.y);
	double s2 = (s.b.y - s.a.y) * (p.x - s.a.x);
	double eps = meps * (std::abs(s1) + std::abs(s2));
	double res = s1 - s2;
	if (res > eps)
		return LEFT;
	if (res < -eps)
		return RIGHT;
	return EQUAL;
}


#include "assert.h"
Sign orientation(const segment& s, const point& p)
{
	Sign sign = orientation_epsilon(s, p);
	if (sign != EQUAL)
		return sign;
	return orientation_essa(s, p);
}

