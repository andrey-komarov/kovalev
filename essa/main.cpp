#include "segment.h"
#include "point.h"
#include <iostream>
#include "orientation.h"

#include <cstdlib>

using namespace std;

int main()
{
	int it = 10000000;
	int sp = 0, sn = 0;
	for (int i = 0; i < it; i++)
	{
		point p1(rand(), rand());
		point p2(rand(), rand());
		point p3(rand(), rand());
		segment s(p1, p2);
		if (orientation(s, p1) == 0)
			sn++;
		else 
			sp++;
	}
	cerr << sn << " " << sp << "\n";
}
