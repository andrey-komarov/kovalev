#include <fstream>

long long gcd(long long a, long long b, long long& x, long long& y)
{
	if (a == 0)
	{
		y = 1;
		x = 0;
		return b;
	}
	long long x1, y1, g;
	g = gcd(b % a, a, x1, y1);
	x = y1 - b / a * x1;
	y = x1;
	return g;
}

int main()
{
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	long long x, y;
	long long a, b, c;
	while (in >> a >> b >> c)
	{
		long long g = gcd(a, b, x, y);
		if (a == 0 && b == 0)
		{
			if (c == 0) 
				out << "0 0\n";
			else
				out << "<none>\n";
		}
		else if (c % g != 0)
		{
			out << "<none>\n";
		}
		else
		{
			long long coef = c / g;
			out << (x * coef) << " " << (y * coef) << "\n";
		}
	}
}