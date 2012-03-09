#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "calculator.h"
#include "function.h"

using namespace std;

int main()
{
	std::ifstream in("in.txt");
	std::ofstream out("out.txt");
    std::string s;
    while (getline(in, s))
    {
        if (s.empty())
            break;
        try
        {
			big_int ans = calculate(s);
			out << ans << "\n";
		}
		catch (std::runtime_error e)
		{
			out << "<error>\n";
		}
		catch (std::exception e)
		{
			out << "<error>\n";
		}
		
    }
    return 0;	
}
