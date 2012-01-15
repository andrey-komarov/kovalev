#include "enum.h"
#include "priority_queue.h"
#include "double_utils.h"

template<int n>
Sign signum(double* values)
{
	priority_queue<n, double> a;
	priority_queue<n, double> b;
	for (size_t i = 0; i < n; i++)
	{
		double &val = values[i];
		if (val > 0)
			a.push(val);
		if (val < 0)
			b.push(-val);
	}
	while (true)
	{
		size_t sz1 = a.size();
		size_t sz2 = b.size();
		if (sz1 == 0 && sz2 == 0)
			return EQUAL;
		if (sz1 == 0)
			return LESS;
		if (sz2 == 0)
			return GREATER;
		double a1 = a.pop();
		double b1 = b.pop();
		if (a1 == b1)
			continue;
		if (a1 > 2 * sz2 * b1)
			return GREATER;
		if (b1 > 2 * sz1 * a1)
			return LESS;
		int e1 = exponent(a1);
		int f1 = exponent(b1);
		if (e1 == f1)
		{
			if (a1 > b1)
				a.push(a1 - b1);
			else
				b.push(b1 - a1);
		}
		else if (e1 < f1)
		{
			double u = pow2(e1 + 1);
			b.push(b1 - u);
			b.push(u - a1);	
		}
		else 
		{
			double u = pow2(f1 + 1);
			a.push(a1 - u);
			a.push(u - b1);
		}
	}
}
