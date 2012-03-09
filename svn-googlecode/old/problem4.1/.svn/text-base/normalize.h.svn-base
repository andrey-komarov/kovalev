#ifndef normalizeH
#define normalizeH

#include "list.h"
#include "list_utils.h"
#include "normalize_positive.h"
#include "normalize_negative.h"


template<typename T>
struct NORMALIZE
{
	typedef 
	typename NORMALIZE_NEGATIVE<
		0, 
		typename NORMALIZE_POSITIVE<
			0, 
			T
		>::type
	>::type type;
};

#endif /* normalizeH */
