#include <iostream>
#include "tree.h"

using namespace std;

int main()
{
    tree<int> t;
    for (int i = 0; i < 100000; i++)
        t.insert(i);
    cerr << t.depth();
}
