#include <iostream>
#include <limits>
//#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <fstream>

#include "intersection.h"
#include "segment.h"

class RandomInput
{
	int seed;

	static const int a = 1664525;
	static const int c = 1013904223;
	public:
	RandomInput(int seed)
		:seed(seed)
	{ }

	// returns random integer in range 0 .. 2^31-1
	int get_int()
	{
		return (seed = seed * a + c) & 0x7fffffff;
	}

	double get_double()
	{
		const double lo = -1000;
		const double hi = 1000;
		const double scale = 1. / (1 << 30);
		return (lo + (hi - lo) * scale * (get_int() & 0x3fffffff));
	}
};


/*
int get_result(std::vector<bool> const & intersects)
{
	int p = 1;
	int res = 0;
	for (size_t i = 0; i < intersects.size(); ++i, p *= 239) {
		if (intersects[i])
			res += p;
	}
	return res;
}
*/

int main()
{
	using std::cin;
	using std::cout;
	using std::cerr;

	//freopen("x", "r", stdin);

	int n, t, seed = 0;
	cin >> n >> t;
	RandomInput generator(0);
	if (t == 1)
	{
		cin >> seed;
		generator = RandomInput(seed);
	}
//	std::vector<bool> intersections(n);
	int P = 1;
	int res = 0;
	for (int i = 0; i < n; i++, P *= 239)
	{
		point p[4];
		if (seed == 0)
		{
			cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> p[2].x >> p[2].y >> p[3].x >> p[3].y;
		}
		else 
		{
			p[0].x = generator.get_double();
			p[0].y = generator.get_double();
			p[1].x = generator.get_double();
			p[1].y = generator.get_double();
			p[2].x = generator.get_double();
			p[2].y = generator.get_double();
			p[3].x = generator.get_double();
			p[3].y = generator.get_double();
		}
		segment s1(p[0], p[1]), s2(p[2], p[3]);
		if (intersects(s1, s2))
			res += P;
	}
	cout << res; 
	return 0;
}
