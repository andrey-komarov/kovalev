#ifndef list_utilsH
#define list_utilsH

#include "list.h"

template<bool C, typename A, typename B>
struct IF
{
};

template<typename A, typename B>
struct IF<true, A, B>
{
	typedef A type;
};

template<typename A, typename B>
struct IF<false, A, B>
{
	typedef B type;
};

template<typename T>
struct LEN
{
	enum {value = 1 + LEN<typename T::Tail>::value};
};

template<>
struct LEN<EmptyList>
{
	enum {value = 0};
};

template<typename T, digit_t A>
struct APPEND
{
	typedef L<T::Head, typename APPEND<typename T::Tail, A>::type> type;
};

template<digit_t A>
struct APPEND<EmptyList, A>
{
	typedef L<A, EmptyList> type;
};

template<typename T>
struct REVERSE
{
	typedef typename APPEND<
		typename REVERSE<typename T::Tail>::type,
		T::Head
	>::type type;
};

template<>
struct REVERSE<EmptyList>
{
	typedef EmptyList type;
};

template<typename T>
struct REMOVE_LEADING_ZEROES
{
	typedef 
	typename IF<
		(T::Head == 0),
		typename REMOVE_LEADING_ZEROES<
			typename T::Tail
		>::type,
		T
	>::type type;
};

template<>
struct REMOVE_LEADING_ZEROES<EmptyList>
{
	typedef EmptyList type;
};

template<int CNT, typename T>
struct ADD_LEADING_ZEROES
{
	typedef L<
		0, 
		typename ADD_LEADING_ZEROES<CNT - 1, T>::type
	> type;
};

template<typename T>
struct ADD_LEADING_ZEROES<0, T>
{
	typedef T type;
};

#endif /* list_utilsH */
