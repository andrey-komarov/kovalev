#ifndef TREENODE_H
#define TREENODE_H

template<typename T>
struct tree<T>::node
{
    enum class Color
    {
        RED, BLACK
    };

    node(const_reference, Color = Color::RED);

    static size_t depth(typename tree<T>::pnode&);
    static void insert(typename tree<T>::pnode&, const_reference, const typename tree<T>::pnode& = nullptr);

private:
    T val;
    pnode left, right, parent;
    Color color;
};

#include "treenode.hpp"

#endif // TREENODE_H
