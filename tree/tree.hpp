#include "tree.h"

template<typename T>
tree<T>::tree() :
    root(nil<T>())
{}

template<typename T>
void tree<T>::insert(const_reference val)
{
    if (count(val) != 0)
        return;
    root = node::insert(root, val);
    if (fixit_insert<T>() != nil<T>())
    {
        insert_case1<T>(fixit_insert<T>());
        fixit_insert<T>() = nil<T>();
        while (root->parent != nil<T>())
            root = root->parent;
    }
}

template<typename T>
void tree<T>::erase(const_reference val)
{
    node::erase(root, val);
    while (root->parent != nil<T>())
        root = root->parent;
}

template<typename T>
size_t tree<T>::count(const_reference val)
{
    return node::count(root, val);
}

template<typename T>
void print(std::ostream& out, const typename tree<T>::pnode& t)
{
    if (t == nil<T>())
        return;
    print<T>(out, t->left);
    out << t->val << " ";
    print<T>(out, t->right);
    return;
}

template<typename T>
std::ostream& operator<< (std::ostream& out, const tree<T> t)
{
    print<T>(out, t.root);
    return out;
}

template<typename T>
size_t tree<T>::depth()
{
    return node::depth(root);
}
