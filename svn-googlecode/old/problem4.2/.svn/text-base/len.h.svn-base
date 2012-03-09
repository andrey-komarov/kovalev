#ifndef lenH
#define lenH

#include "list.h"

template<typename T>
struct LEN
{
	static const int value = 1 + LEN<typename T::Tail>::value;
};

template<>
struct LEN<EmptyList>
{
	static const int value = 0;
};

#endif /* lenH */
