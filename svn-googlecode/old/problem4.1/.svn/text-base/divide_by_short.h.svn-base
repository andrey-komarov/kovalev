#ifndef divide_by_shortH
#define divide_by_shortH

#include "list.h"
#include "list_utils.h"

template<digit_t carry, typename T, digit_t A>
struct DIVIDE_BY_SHORT_
{
	typedef 
	typename DIVIDE_BY_SHORT_<
		0,
		L<T::Head + carry, typename T::Tail>,
		A
	>::type type;
};

template<digit_t carry, digit_t A>
struct DIVIDE_BY_SHORT_<carry, EmptyList, A>
{
	typedef EmptyList type;
};

template<typename T, digit_t A>
struct DIVIDE_BY_SHORT_<0, T, A>
{
	typedef L<
		T::Head / A,
		typename DIVIDE_BY_SHORT_<
			(T::Head % A) * BASE, 
			typename T::Tail,
			A
		>::type
	> type;
};

template<digit_t A>
struct DIVIDE_BY_SHORT_<0, EmptyList, A>
{
	typedef EmptyList type;
};

template<typename T, digit_t A>
struct DIVIDE_BY_SHORT
{
	typedef
	typename REMOVE_LEADING_ZEROES<
		typename DIVIDE_BY_SHORT_<0, T, A>::type
	>::type type;

};


#endif /* divide_by_shortH */
