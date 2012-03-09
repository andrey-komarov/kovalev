#include <iostream>
#include <fstream>

#include "add.h"
#include "list_utils.h"
#include "subtract.h"
#include "multiply.h"
#include "divide_by_short.h"
#include "less.h"
#include "equals.h"
#include "divide.h"

using namespace std;

ostream& operator<<(ostream& out, EmptyList)
{
	return out;
}

template<digit_t A, typename T>
ostream& operator<<(ostream& out, L<A, T> a)
{
	out << a.Head << T();
	return out;
}

int main()
{
	typedef L<1, L<0, L<7, EmptyList> > > list;
	typedef L<1, L<3, EmptyList> > list2;
	cout << DIVIDE<list, list2>::type() << "\n";
}
