#include <iostream>

#include <cassert>
#include <cstdlib>
#include <cmath>

#include "skiplist.h"

using namespace std;

template<typename Iterator>
struct Cmp
{
    int cmp_with;
    Cmp(const int& cmp_with) :
        cmp_with(cmp_with)
    {}

    bool operator()(const Iterator& it) const
    {
        return *it < cmp_with;
    }
};

typedef Cmp<typename skiplist<int>::iterator> Cmpp;

int main()
{
    skiplist<int> a;

    for (int i = 0; i < 100000; i++)
    {
        int r = rand();
        a.insert (a.lower_bound(Cmpp(r)), r);
    }
    for (auto it : a)
        cerr << it << " ";
}
