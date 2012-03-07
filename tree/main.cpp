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
//    int k = 100000;
//    for (int i = 0; i < n; i++)
//    {
//        int elem = rand() % k;
//        cerr << i << " ";
//        if ((rand() & 1) == 0)
//        {
//            cerr << "inserting " << elem << "...\n";
//            s.insert(elem);
//            t.insert(elem);
//            t.check_rb_properties();
//        }
//        else if ((rand() & 1) == 0)
//        {
//            cerr << "checking " <<elem << " " << s.size() << "...\n";
//            assert (s.count(elem) == t.count(elem));
//        }
//        else
//        {
//            cerr << "removing " << elem << "...\n";
//            t.erase(elem);
//            t.check_rb_properties();
//            s.erase(elem);
//        }
//    }
//    for (int i = 0; i < 20; i++)
//    {
//        t.insert(i);
//    }
//    for (int i = 0; i < 20; i++)
//        t.erase(i);
//    for (int i = 0; i < 10; i++)
//        t.insert(i);
//    for (tree<int>::iterator it = t.begin(); it != t.end(); it++)
//    {
//        cerr << *it << " ";
//    }
    t.insert(1);

    for (int i = 0; i < 10; i++)
        t.insert(2 * i);
//    for (int i = 0; i < 5; i++)
//        t.erase(4 * i);
//    for (int i = 0; i < 20; i++)
//        cerr << t.count(i);
//    t.erase(0);

    for (auto x : t)
        cerr << x << " ";

}
