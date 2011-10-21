#include <iostream>
#include <vector>

#include "segment.h"

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i % (n / 10) == 0)
            cerr << "\r" << i << "\n";
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segment s1(point(x1, y1), point(x2, y2));
        cin >> x1 >> y1 >> x2 >> y2;
        segment s2(point(x1, y1), point(x2, y2));
        cout << intersects(s1, s2);
    }
}
