#ifndef multiplyH
#define multiplyH

#include "list.h"
#include "list_utils.h"
#include "add.h"
#include "normalize.h"
#include "multiply_by_short.h"

template<typename T1, typename T2>
struct MULTIPLY_
{
	typedef 
	typename ADD_<
		typename ADD_LEADING_ZEROES<
			(LEN<T2>::value - 1),
			typename MULTIPLY_BY_SHORT<T1, T2::Head>::type
		>::type,
		typename MULTIPLY_<T1, typename T2::Tail>::type
	>::type type;
};

template<typename T1>
struct MULTIPLY_<T1, EmptyList>
{
	typedef EmptyList type;
};

template<typename T2>
struct MULTIPLY_<EmptyList, T2>
{
	typedef EmptyList type;
};

template<typename T1, typename T2>
struct MULTIPLY
{
	typedef 
	typename REVERSE<
		typename NORMALIZE<
			typename MULTIPLY_<
				typename REVERSE<T1>::type,
				T2
			>::type
		>::type
	>::type type;
};

#endif /* multiplyH */
