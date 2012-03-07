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
    struct iterator;

private:
    struct node;
    struct patch;
    struct helper;

    typedef std::shared_ptr<patch> ppatch;
    typedef std::shared_ptr<node> pnode;
//    typedef node* pnode;

public:
    tree();
    void insert(const_reference elem);
    void erase(const_reference elem);
    size_t count(const_reference elem);

    void search_in(size_t rev);

    void check_rb_properties() ;

    iterator begin();
    iterator end();

    size_t depth() ;

private:
    helper h;
};

template<typename T>
typename tree<T>::pnode& nil();

#include "patch.h"
#include "helper.h"
#include "treenode.h"
#include "iterator.h"
#include "tree.hpp"

#endif // TREE_H
