#include "tree.h"

template<typename T>
tree<T>::tree() :
    t(nullptr)
{}

template<typename T>
void tree<T>::insert(const_reference val)
{
    node::insert(t, val);
    while (t->parent != nullptr)
        t = t->parent;
}

template<typename T>
void print(std::ostream& out, T& t)
{
    if (t == nullptr)
        return;
    print(out, t->left);
    out << t->val << " ";
    print(out, t->right);
    return;
}

template<typename T>
std::ostream& operator<< (std::ostream& out, const tree<T> t)
{
    print(out, t.t);
    return out;
}

template<typename T>
size_t tree<T>::depth()
{
    return node::depth(t);
}
