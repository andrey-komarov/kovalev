#ifndef TREE_H
#define TREE_H

#include <cstddef>
#include <ostream>
#include <memory>
#include <cassert>

size_t ROTATES;
size_t NODES;

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
    static const size_t max_revision = ((long long)1) << 60;

    struct node;
    struct patch;
    struct helper;
    struct revision;

//    typedef std::shared_ptr<patch> ppatch;
//    typedef std::shared_ptr<node> pnode;
    typedef node* pnode;
    typedef patch* ppatch;

public:
    tree();
    void insert(const_reference elem);
    void erase(const_reference elem);

    size_t size() const;
    size_t size(size_t rev) const;

    size_t count(const_reference elem) const;
    size_t count(const_reference elem, size_t revision) const;

    void tag_it(size_t rev);

    void check_rb_properties() const;

    iterator begin();
    iterator end();
    iterator begin(size_t);


    size_t depth() const;

private:
    helper h;
};

template<typename T>
typename tree<T>::pnode& nil();

#include "revision.h"
#include "patch.h"
#include "helper.h"
#include "treenode.h"
#include "iterator.h"
#include "tree.hpp"

#endif // TREE_H
