#ifndef lessH
#define lessH

#include "list.h"
#include "list_utils.h"

template<bool C, bool A, bool B>
struct IF_LESS_HELPER
{
};

template<bool A, bool B>
struct IF_LESS_HELPER<true, A, B>
{
	enum {value = A};
};

template<bool A, bool B>
struct IF_LESS_HELPER<false, A, B>
{
	enum {value = B};
};

template<typename T1, typename T2>
struct LESS_
{
	enum {value = 
		IF_LESS_HELPER<
			(digit_t)T1::Head != (digit_t)T2::Head,
			((digit_t)T1::Head < (digit_t)T2::Head),
			LESS_<
				typename T1::Tail,
				typename T2::Tail
			>::value
		>::value
	};
};

template<>
struct LESS_<EmptyList, EmptyList>
{
	enum {value = false};
};

template<typename T1>
struct LESS_<T1, EmptyList>
{
	enum {value = false};
};

template<typename T2>
struct LESS_<EmptyList, T2>
{
	enum {value = false};
};

template<typename T1, typename T2>
struct LESS
{
	enum {value = 
		IF_LESS_HELPER<
			(int)LEN<T1>::value != (int)LEN<T2>::value,
			((int)LEN<T1>::value < (int)LEN<T2>::value),
			LESS_<T1, T2>::value
		>::value
	};
};

#endif /* lessH */
