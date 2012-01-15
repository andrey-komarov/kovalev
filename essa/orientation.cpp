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

Sign orientation(const segment& s, const point& p)
{
	return orientation_essa(s, p);
}

