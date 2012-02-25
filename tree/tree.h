#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include <ostream>
#include <memory>
#include <cassert>

// Расстрел
#define private public

template<typename T>
struct tree
{
    typedef T key_type;
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;

private:
    struct node;
    typedef std::shared_ptr<node> pnode;
//    typedef node* pnode;

public:
    tree();
    void insert(const_reference elem);
    void erase(const_reference elem);
    size_t count(const_reference elem);

    void check_rb_properties() const;

    struct iterator
    {
//        typedef std::bidirectional_iterator_tag iterator_category; // TODO
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
        pointer operator->();
        iterator& operator++();
        iterator operator++(int);
        bool operator==(const iterator&) const;
        bool operator!=(const iterator&) const;
    private:
        iterator (tree<T>* t, pnode n);

        tree<T>* t;
        pnode n;
        friend class tree<T>;
    };

    iterator begin();
    iterator end();

    size_t depth();

private:
    pnode root;
};

template<typename T>
typename tree<T>::pnode& nil();

#include "treenode.h"
#include "iterator.hpp"
#include "tree.hpp"

#endif // TREE_H
