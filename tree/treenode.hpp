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

template<typename T>
auto tree<T>::node::left() -> pnode&
{
    return left_;
}

template<typename T>
auto tree<T>::node::right() -> pnode&
{
    return right_;
}
