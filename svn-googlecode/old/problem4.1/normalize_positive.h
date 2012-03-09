#ifndef normalize_positiveH
#define normalize_positiveH

#include "list.h"

template<digit_t carry, typename T>
struct NORMALIZE_POSITIVE
{
	typedef 
	typename NORMALIZE_POSITIVE<
		0,
		L<
			(T::Head + carry), 
			typename T::Tail
		> 
	>::type type;
};

template<typename T>
struct NORMALIZE_POSITIVE<0, T>
{
	typedef 
	L<
		T::Head % BASE,
		typename NORMALIZE_POSITIVE<
			T::Head / BASE,
			typename T::Tail
		>::type
	> type;
};

template<>
struct NORMALIZE_POSITIVE<0, EmptyList>
{
	typedef EmptyList type;
};

template<digit_t carry>
struct NORMALIZE_POSITIVE<carry, EmptyList>
{
	typedef 
	typename NORMALIZE_POSITIVE<
		0,
		L<
			carry, 
			EmptyList
		>
	>::type type;
};

#endif /* normalize_positiveH */ 
