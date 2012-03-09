#ifndef divideH
#define divideH

#include "list.h"
#include "list_utils.h"
#include "add.h"
#include "multiply.h"
#include "divide_by_short.h"

template<typename T1, typename T2, typename LEFT, typename RIGHT, typename CENTER>
struct DIVIDE_BIN_SEARCH
{
	typedef 
	typename IF<
		LESS<
			T1,
			typename MULTIPLY<
				T2,
				CENTER
			>::type
		>::value,
		typename DIVIDE_BIN_SEARCH<
			T1,
			T2,
			LEFT,
			CENTER, 
			typename DIVIDE_BY_SHORT<
				typename ADD<
					LEFT,
					CENTER
				>::type,
				2
			>::type
		>::type,
		typename DIVIDE_BIN_SEARCH<
			T1,
			T2,
			CENTER,
			RIGHT,
			typename DIVIDE_BY_SHORT<
				typename ADD<
					CENTER,
					RIGHT
				>::type,
				2
			>::type
		>::type
	>::type type;
};

template<typename T1, typename T2, typename LEFT, typename RIGHT>
struct DIVIDE_BIN_SEARCH<T1, T2, LEFT, RIGHT, LEFT>
{
	typedef LEFT type;
};


template<typename T1, typename T2>
struct DIVIDE_
{
	typedef
	typename DIVIDE_BIN_SEARCH<
		T1, 
		T2, 
		EmptyList, 
		T1, 
		typename DIVIDE_BY_SHORT<
			T1, 
			2
		>::type
	>::type type;
};

template<typename T1, typename T2>
struct DIVIDE
{
	typedef
	typename REMOVE_LEADING_ZEROES<
		typename DIVIDE_<T1, T2>::type
	>::type type;
};

#endif /* divideH */

