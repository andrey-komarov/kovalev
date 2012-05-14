#ifndef ITERATOR_H
#define ITERATOR_H

#include "skiplist.h"

template<typename T>
struct skiplist<T>::iterator
{
    iterator& operator=(const iterator&);

    const T& operator*() const;

    iterator& operator++();
    iterator operator++(int);

    bool operator==(const iterator&) const;
    bool operator!=(const iterator&) const;
private:
    iterator(const wpnode& n);

    wpnode n;

    friend struct skiplist<T>;
};

#include "iterator.hpp"

#endif // ITERATOR_H
