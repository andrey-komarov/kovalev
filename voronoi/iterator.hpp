#include "iterator.h"

template<typename T>
skiplist<T>::iterator::iterator(const wpnode &n):
    n(n)
{}

template<typename T>
auto skiplist<T>::iterator::operator=(const iterator& it) -> iterator&
{
    n = it.n;
}

template<typename T>
const T& skiplist<T>::iterator::operator*() const
{
    return n.lock()->value;
}

template<typename T>
auto skiplist<T>::iterator::operator++() -> iterator&
{
    pnode p = n.lock();
    if (p == nullptr)
        return *this;
    n = p->forward[0];
    return *this;
}

template<typename T>
auto skiplist<T>::iterator::operator++(int) -> iterator
{
    iterator it = *this;
    operator++();
    return it;
}

template<typename T>
bool skiplist<T>::iterator::operator==(const iterator& it) const
{
    return n.lock() == it.n.lock();
}

template<typename T>
bool skiplist<T>::iterator::operator!=(const iterator& it) const
{
    return !operator==(it);
}
