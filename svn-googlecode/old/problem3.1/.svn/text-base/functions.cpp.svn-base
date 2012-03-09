#include "big_int.h"
#include "function.h"

big_int sqr(big_int a)
{
	return a * a;
}

big_int fortytwo(big_int a)
{
	return 42;
}

big_int sign(big_int a)
{
	if (a == 0)
		return 0;
	return a < 0 ? -1 : 1;
}

big_int fact(big_int a)
{
	if (a < 0)
		throw std::runtime_error("factorial of negative number");
	big_int res = 1;
	for (big_int i = 2; i <= a; i += 1)
		res *= i;
	return res;
}

big_int digits(big_int a)
{
	big_int len;
	a = abs(a);
	if (a < 10)
		return 1;
	big_int tmp = 1;
	for (; tmp <= a; len += 1)
		tmp *= 10;
	return len;
}

add_function("sqr", sqr);
add_function("fortytwo", fortytwo);
add_function("sign", sign);
add_function("fact", fact);
add_function("digits", digits);
