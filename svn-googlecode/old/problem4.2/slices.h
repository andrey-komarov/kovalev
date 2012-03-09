#ifndef slicesH
#define slicesH

#include "len.h"

template<int CNT, typename T>
struct PREFIX
{
	typedef LIST<T::Head, typename PREFIX<CNT - 1, typename T::Tail>::type> type;
};

template<typename T>
struct PREFIX<0, T>
{
	typedef EmptyList type;
};


template<int CNT, typename T>
struct SUFFIX
{
	typedef typename SUFFIX<CNT - 1, typename T::Tail>::type type;
};

template<typename T>
struct SUFFIX<0, T>
{
	typedef T type;
};

#endif /* slicesH */
