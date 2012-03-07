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
    node();

    static size_t depth(typename tree<T>::pnode&);
    static typename tree<T>::pnode insert(typename tree<T>::pnode, const_reference, const typename tree<T>::pnode& parent = nil<T>());
    static typename tree<T>::pnode erase(typename tree<T>::pnode, const_reference);
    static typename tree<T>::pnode erase(typename tree<T>::pnode);
    static size_t count(typename tree<T>::pnode&, const_reference);

    pnode& left_(size_t revision);
    pnode& right_(size_t revision);
    pnode& parent_(size_t revision);

private:
    T val;
    pnode left, right, parent;
    Color color;
    ppatch patch;
};

#include "treenode.hpp"

#endif // TREENODE_H
