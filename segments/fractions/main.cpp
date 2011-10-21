#include <iostream>
#include <vector>

#include "fractions/segment.h"

using namespace std;

int main()
{
    segment s(point(0, 0), point(1, 0));
    segment s2(point(0, 1), point(1, 1));
    cerr << intersects(s, s2) << "\n";
}
