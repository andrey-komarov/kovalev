//#define private public

#include <iostream>

#include "number.h"
#include <cassert>
#include <cstdlib>
#include <cmath>

#include "skiplist.h"

using namespace std;

template<typename T>
int sgn(const T& a)
{
    if (a == 0)
        return 0;
    return a < 0 ? - 1: 1;
}


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

#include <map>

int main()
{
    skiplist<int> a;

    for (int i = 0; i < 1000000; i++)
    {
        int r = rand();
        a.insert (lower_bound(a, Cmpp(r)), r);
    }

//    map<int, int> heights;
//    for (skiplist<int>::iterator i = a.begin (); i != a.end (); i++)
//        heights[i.n.lock()->forward.size()]++;
//    for (auto it : heights)
//        cerr << it.first << " : " << it.second << "\n";
//        cerr << *i << " ";
}
