#include "intersection.h"
#include "orientation.h"

bool check_bbox_intersection(const segment& s1, const segment& s2)
{
	double min1;
	double max1;
	if (s1.a.x < s1.b.x)
		min1 = s1.a.x, max1 = s1.b.x; // Инвче ну слишком длинный код >_<
	else 
		min1 = s1.b.x, max1 = s1.a.x;

	double min2;
	double max2;
	if (s2.a.x < s2.b.x)
		min2 = s2.a.x, max2 = s2.b.x;
	else 
		min2 = s2.b.x, max2 = s2.a.x;

	if (max2 < min1 || max1 < min2)
		return false;
	
	if (s1.a.y < s1.b.y)
		min1 = s1.a.y, max1 = s1.b.y;
	else
		min1 = s1.b.y, max1 = s1.a.y;

	if (s2.a.y < s2.b.y)
		min2 = s2.a.y, max2 = s2.b.y;
	else
		min2 = s2.b.y, max2 = s2.a.y;
	
	if (max2 < min1 || max1 < min2)
		return false;
	return true;
}

bool intersects(const segment& s1, const segment& s2)
{
	if (!check_bbox_intersection(s1, s2))
		return false;
	if (orientation(s1, s2.a) * orientation(s1, s2.b) > 0)
		return false;
	if (orientation(s2, s1.a) * orientation(s2, s1.b) > 0)
		return false;
	return true;
}

