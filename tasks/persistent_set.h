#ifndef persistent_set_h
#define persistent_set_h

#include "set.h"
#include <map>
#include <cstdlib>
#include <functional>

namespace geom
{

template<typename T, typename cmp = std::less<T> >
struct persistent_set : set<T, cmp>
{
	virtual void tag_revision(size_t id) = 0;
	virtual void restore_revision(size_t id) = 0;
};

} // geom

#endif // persistent_set_h
