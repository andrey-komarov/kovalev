#ifndef listH
#define listH

struct EmptyList{};

template<int A, typename T>
struct LIST{
	typedef T Tail;
	static const int Head = A;
};

#endif /* listH */
