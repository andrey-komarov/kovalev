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
    struct patch;
    struct helper;
    struct iterator;


    typedef std::shared_ptr<patch> ppatch;
    typedef std::shared_ptr<node> pnode;
//    typedef node* pnode;

public:
    tree();
    void insert(const_reference elem);
    void erase(const_reference elem);
    size_t count(const_reference elem);

    void check_rb_properties() const;

    iterator begin();
    iterator end();

    size_t depth() const;

private:
    helper h;
};

template<typename T>
typename tree<T>::pnode& nil();

#include "patch.h"
#include "treenode.h"
#include "iterator.hpp"
#include "tree.hpp"

#endif // TREE_H
