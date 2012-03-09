#ifndef multiply_by_shortH
#define multiply_by_shortH

#include "list.h"
// For inner use only
// Warning: multiplies reversed number!

template<typename T, digit_t A>
struct MULTIPLY_BY_SHORT_
{
	typedef L<
		T::Head * A, 
		typename MULTIPLY_BY_SHORT_<
			typename T::Tail, 
			A
		>::type
	> type;
};

template<digit_t A>
struct MULTIPLY_BY_SHORT_<EmptyList, A>
{
	typedef EmptyList type;
};

template<typename T, digit_t A>
struct MULTIPLY_BY_SHORT
{
	typedef 
	typename NORMALIZE<
		typename MULTIPLY_BY_SHORT_<
			T, 
			A
		>::type
	>::type type;
};

#endif /* multiply_by_shortH */
