#ifndef ITERATOR_H
#define ITERATOR_H

template<typename T>
struct tree<T>::iterator
{
    typedef std::forward_iterator_tag iterator_category;
    typedef tree::value_type value_type;
    typedef tree::size_type size_type;
    typedef tree::difference_type difference_type;
    typedef tree::pointer pointer;
    typedef tree::const_pointer const_pointer;
    typedef tree::reference reference;
    typedef tree::const_reference const_reference;

    iterator& operator=(const iterator&);

    const_reference operator*();
//    pointer operator->();
    iterator& operator++();
    iterator operator++(int);
    bool operator==(const iterator&) const;
    bool operator!=(const iterator&) const;
private:
    iterator (tree<T>* t, pnode n);

    size_t revision;
    tree<T>* t;
    pnode n;
    friend class tree<T>;
};

#include "iterator.hpp"

#endif // ITERATOR_H
