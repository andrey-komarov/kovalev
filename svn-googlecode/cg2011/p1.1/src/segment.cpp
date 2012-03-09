#include "segment.h"

segment::segment()
{}

segment::segment(const point& a, const point& b): a(a), b(b)
{}

std::ostream& operator<<(std::ostream& out, const segment& s)
{	return out << "[" << s.a << "; " << s.b << "]";}
