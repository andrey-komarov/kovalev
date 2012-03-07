#ifndef TREENODE_H
#define TREENODE_H

template<typename T>
struct tree<T>::node
{
    enum class Color
    {
        RED, BLACK
    };

    node(const_reference, Color, pnode nil);
    node(const_reference, Color, pnode left, pnode right, pnode parent);
    node();

    pnode apply() const;

    static size_t depth(typename tree<T>::pnode&);
    static typename tree<T>::pnode insert(typename tree<T>::pnode, const_reference, const typename tree<T>::pnode& parent = nil<T>());
    static typename tree<T>::pnode erase(typename tree<T>::pnode, const_reference);
    static typename tree<T>::pnode erase(typename tree<T>::pnode);
    static size_t count(typename tree<T>::pnode&, const_reference);

private:
    T val;
    pnode left_, right_, parent;
    Color color;
    ppatch patch;

    friend class tree<T>;
};

#include "treenode.hpp"

#endif // TREENODE_H
