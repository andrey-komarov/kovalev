#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include <ostream>
#include <memory>

// Расстрел
#define private public

template<typename T>
struct tree
{
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

    tree();
    void insert(const_reference elem);

    struct iterator
    {
        typedef std::random_access_iterator_tag iterator_category;
        typedef tree::value_type value_type;
        typedef tree::size_type size_type;
        typedef tree::difference_type difference_type;
        typedef tree::pointer pointer;
        typedef tree::const_pointer const_pointer;
        typedef tree::reference reference;
        typedef tree::const_reference const_reference;
//		reference operator*();
//		pointer operator->();
//		iterator& operator++();
//		iterator operator++(int);
//		iterator& operator--();
//		iterator operator--(int);
//		iterator& operator=(const iterator&);
//		bool operator==(const iterator&) const;
//		bool operator!=(const iterator&) const;
    };
    int a;

    size_t depth();

private:
    struct node;
    typedef std::shared_ptr<node> pnode;
//    typedef node* pnode;

    pnode t;
};

//template<typename T>
//std::ostream& operator<<(std::ostream& out, const typename tree<T>::node& t);

//template<typename T>
//std::ostream& operator<<(std::ostream& out, const tree<T>& t);

#include "treenode.h"
#include "tree.hpp"

#endif // TREE_H
