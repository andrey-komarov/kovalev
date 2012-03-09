#ifndef subtractH
#define subtractH

#include "list.h"
#include "list_utils.h"
#include "normalize.h"
#include "negate.h"

template<typename T1, typename T2>
struct SUBTRACT_
{
	typedef L<
		T1::Head - T2::Head, 
		typename SUBTRACT_<
			typename T1::Tail,
			typename T2::Tail
		>::type
	> type;
};

template<typename T1>
struct SUBTRACT_<T1, EmptyList>
{
	typedef T1 type;
};

template<typename T2>
struct SUBTRACT_<EmptyList, T2>
{
	typedef typename NEGATE<T2>::type type;
};

template<>
struct SUBTRACT_<EmptyList, EmptyList>
{
	typedef EmptyList type;
};

template<typename T1, typename T2>
struct SUBTRACT
{
	typedef 
	typename REMOVE_LEADING_ZEROES<
		typename REVERSE<
			typename NORMALIZE<
				typename SUBTRACT_<
					typename REVERSE<T1>::type,
					typename REVERSE<T2>::type
				>::type
			>::type
		>::type
	>::type type;
};

#endif /* subtractH */

