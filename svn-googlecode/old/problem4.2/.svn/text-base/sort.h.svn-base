#ifndef sortH
#define sortH

#include "list.h"
#include "len.h"
#include "merge.h"
#include "slices.h"

template<typename T>
struct SORT
{
	typedef	typename MERGE<
		typename SORT<typename PREFIX<LEN<T>::value / 2, T>::type>::type,
		typename SORT<typename SUFFIX<LEN<T>::value / 2, T>::type>::type
	>::type type;
};

template<>
struct SORT<EmptyList>
{
	typedef EmptyList type;
};

template<int A>
struct SORT<LIST<A, EmptyList> >
{
	typedef LIST<A, EmptyList> type;
};

#endif /* sortH */
