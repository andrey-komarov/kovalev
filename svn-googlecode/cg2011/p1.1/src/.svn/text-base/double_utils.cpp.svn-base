#include "double_utils.h"

int exponent(double d)
{
//	long long dd = reinterpret_cast<long long>(d);  // WTF??? Compile error
	union
	{
		double double_;
		long long long_long_;
	} dd;
	dd.double_ = d < 0 ? -d : d;
	int res = dd.long_long_ >> 52;
	res = res - 1023;
	return res;
}

double pow2(int exponent)
{
	union
	{
		double double_;
		long long long_long_;
	} dd;
	dd.long_long_ = ((long long)exponent + 1023) << 52;
	return dd.double_;
}

void split(double a, size_t s, double& lo, double& hi)
{
	double c = ((1 << s) + 1) * a;
	hi = c - (c - a);
	lo = a - hi;
}

double two_product(double a, double b, double& roundoff)
{
	double x = a * b;
	double a_lo, a_hi, b_lo, b_hi;
	split(a, 26, a_lo, a_hi);
	split(b, 26, b_lo, b_hi);
	double err1 = x - a_hi * b_hi;
	double err2 = err1 - a_lo * b_hi;
	double err3 = err2 - a_hi * b_lo;
	roundoff = a_lo * b_lo - err3;
	return x;
}

