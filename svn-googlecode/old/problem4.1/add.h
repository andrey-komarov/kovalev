#ifndef addH
#define addH

#include "list.h"
#include "list_utils.h"
#include "normalize.h"

template<typename T1, typename T2>
struct ADD_
{
	typedef L<
		T1::Head + T2::Head, 
		typename ADD_<
			typename T1::Tail,
			typename T2::Tail
		>::type
	> type;
};

template<typename T1>
struct ADD_<T1, EmptyList>
{
	typedef T1 type;
};

template<typename T2>
struct ADD_<EmptyList, T2>
{
	typedef T2 type;
};

template<>
struct ADD_<EmptyList, EmptyList>
{
	typedef EmptyList type;
};

template<typename T1, typename T2>
struct ADD
{
	typedef 
	typename REVERSE<
		typename NORMALIZE<
			typename ADD_<
				typename REVERSE<T1>::type,
				typename REVERSE<T2>::type
			>::type
		>::type
	>::type type;
};

#endif /* addH */
