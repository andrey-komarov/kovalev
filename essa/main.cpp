#include "segment.h"
#include <iostream>
#include "intersection.h"

#include <cstdlib>

using namespace std;

int main()
{
	point p1(0, 0);
	point p2(1, 0);
	point p3(0, 1);
	point p4(1, 1);	
	cerr << intersects(segment(p1, p4), segment(p3, p2));
}
