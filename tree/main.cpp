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
    for (int i = 0; i < 4; i++)
        t.insert(i);
//    for (int i = 0; i < 10; i++)
//    {
//        t.erase(9 - i);
//        cerr << t << "\n\n";
//    }
    t.erase(2);
//    t.erase(2);
//    t.erase(1);
    cerr << t << "\n";
}
