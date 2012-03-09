#include <fstream>
#include <vector>

int main()
{
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	std::vector<double> x, y;

	double x1, y1;
	while (in >> x1 >> y1) 
	{
		x.push_back(x1);
		y.push_back(y1);
	}
	double s = 0;
	for (int i = 0, n = x.size(); i < n; i++) 
	{
		s -= x[i] * y[(i + 1) % n] - x[(i + 1) % n] * y[i];
	}
	out << std::fixed << s / 2;
}