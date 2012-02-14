#include "impl/slow_persistent_set.h"

struct a
{
	struct aa{};
	virtual aa ololo();
};


struct b : a
{
	struct bb : aa {};
	bb ololo()
	{
		return bb();
	}
};

int main() 
{
//	b q;
/*	geom::set<int> *s = new geom::slow_persistent_set<int>();
	s->insert(0);
	s->erase(0);
	geom::slow_persistent_set<int>::iterator::value_type a = 1;
*/
}
