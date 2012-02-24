#include <iostream>
#include "tree.h"
#include <set>
#include <cassert>

using namespace std;

int main()
{
    tree<int> t;
//    set<int> s;
//    int n = 10000000;
//    int k = 10000000;
//    for (int i = 0; i < n; i++)
//    {
//        int elem = rand() % k;
//        cerr << i << " ";
//        if ((rand() & 1) == 0)
//        {
//            cerr << "inserting " << elem << "...\n";
//            s.insert(elem);
//            t.insert(elem);
//        }
//        else
//        {
//            cerr << "checking " <<elem << "...\n";
//            assert (s.count(elem) == t.count(elem));
//        }
//    }

    int n = 10;

    for (int i = 0; i < n; i++)
        t.insert(i);
    for (int i = 0; i < n; i++)
    {
        cerr << ((i * 7) % n) << "---";
        t.erase((i * 7) % n);
        cerr << t << "\n\n";
    }
//    t.erase(9);
    cerr << t << "\n";
}
