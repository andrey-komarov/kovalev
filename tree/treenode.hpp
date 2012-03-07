#include "treenode.h"

template<typename T>
tree<T>::node::node() :
    left_(nullptr), right_(nullptr), parent(nullptr),
    color(Color::BLACK)
{

}

template<typename T>
tree<T>::node::node(const_reference val, Color color, pnode nil) :
    val(val),
    left_(nil), right_(nil), parent(nil),
    color(color)
{}
