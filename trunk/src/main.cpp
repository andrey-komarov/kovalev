#include <iostream>
#include <fstream>
#include <vector>

#include "geom/point.h"
#include "geom/segment.h"

using geom::point;
using geom::segment;
using geom::intersects;
using geom::expansion;
using namespace std;

int main()
{
//    point p1(0, 0);
//    point p2(10, 9);
//    point p3(10, 0);
//    point p4(0, 10);
//    segment s1(p1, p2);
//    segment s2(p3, p4);
//    point p = intersect(s1, s2);
//    cerr << (p < p3) << "\n";

    vector<point> points;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        if (i % (n / 10 + 1) == 0)
            cerr << "\r" << i << "\n";
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        segment s1(point(x1, y1), point(x2, y2));
        cin >> x1 >> y1 >> x2 >> y2;
        segment s2(point(x1, y1), point(x2, y2));
        if (intersects(s1, s2))
        {
            point p = intersect(s1, s2);
//            cout << i << " :: " << p << " :: " << (p < point(0, 0)) << "\n";
            points.push_back(p);
        }
        points.push_back(s1.a);
    }
    sort(points.begin(), points.end());
    for (vector<point>::const_iterator it = points.begin(); it != points.end(); it++)
        cout << *it << "\n";
}
