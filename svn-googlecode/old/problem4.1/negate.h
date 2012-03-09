#ifndef negateH
#define negateH

#include "list.h"

template<typename T>
struct NEGATE
{
	typedef L<-T::Head,	typename NEGATE<typename T::Tail>::type> type;
};

template<>
struct NEGATE<EmptyList>
{
	typedef EmptyList type;
};

#endif /* negateH */
