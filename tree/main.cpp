#define private public

#include <iostream>
#include "tree.h"
#include <set>
#include <cassert>

using namespace std;


int main()
{
    tree<int> t;
    int rev = 0;
    int n = 7;
    for (int i = 0; i < n; i++)
    {
        t.insert(17 * i % 10);
        t.tag_it(rev++);
    }
    for (int i = 0; i < n; i++)
    {
        cerr << t.size(i) << " :: ";
        for (auto it = t.begin(i); it != t.end(); it++)
            cerr << *it;
        cerr << "\t\t\t";
        for (auto j : t)
            cerr << t.count(j, i);
        cerr << "\n";
    }
}
