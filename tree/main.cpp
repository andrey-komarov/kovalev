#include <iostream>
#include "tree.h"
#include <set>
#include <cassert>

using namespace std;

int main()
{
    tree<int> t;
    set<int> s;
    int n = 10000000;
    int k = 10000;
    for (int i = 0; i < n; i++)
    {
        int elem = rand() % k;
        cerr << i << " ";
        if ((rand() & 1) == 0)
        {
            cerr << "inserting " << elem << "...\n";
            s.insert(elem);
            t.insert(elem);
            t.check_rb_properties();
        }
        else if (rand() & 1 == 0)
        {
            cerr << "checking " <<elem << "...\n";
            assert (s.count(elem) == t.count(elem));
        }
        else
        {
            cerr << "removing " << elem << "...\n";
            t.erase(elem);
            t.check_rb_properties();
            s.erase(elem);
        }
    }
}
