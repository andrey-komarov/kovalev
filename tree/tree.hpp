#include "tree.h"

template<typename T>
tree<T>::tree() :
    h(this)
{}

template<typename T>
void tree<T>::insert(const_reference elem)
{
    h.insert(elem);
}

template<typename T>
void tree<T>::erase(const_reference elem)
{
    h.erase(elem);
}

template<typename T>
size_t tree<T>::count(const_reference elem) const
{
    return h.count(elem);
}

template<typename T>
void tree<T>::check_rb_properties() const
{
    h.check_rb_properties();
}

template<typename T>
size_t tree<T>::depth() const
{
    return h.depth();
}

template<typename T>
auto tree<T>::begin() -> iterator
{
    return h.begin();
}

template<typename T>
auto tree<T>::begin(size_t rev) -> iterator
{
    return h.begin(rev);
}

template<typename T>
auto tree<T>::end() -> iterator
{
    return h.end();
}

template<typename T>
void tree<T>::tag_it(size_t rev)
{
    h.tag_it(rev);
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

