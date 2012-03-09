#include <fstream>

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int main()
{
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
	int n;
	in >> n;
	int x = 0;
	int y = 0;
	int len = 0;
	int state = 0;
	for (int i = 0; i < n; i++)
	{
		out << x << ' ' << y << '\n';
		len += 1 - i % 2;
		x += dx[state % 4] * len;
		y += dy[state++ % 4] * len;
	}
}