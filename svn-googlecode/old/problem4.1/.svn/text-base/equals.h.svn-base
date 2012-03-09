#ifndef equalsH
#define equalsH

#include "list.h"
#include "list_utils.h"
#include "less.h"

template<typename T1, typename T2>
struct EQUALS
{
	enum {value=
		!(LESS<T1, T2>::value || LESS<T2, T1>::value)
	};
};

#endif /* lessH */

