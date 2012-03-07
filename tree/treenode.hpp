#include "helper.h"

template<typename T>
tree<T>::node::node() :
    left(nullptr), right(nullptr), parent(nullptr),
    color(Color::BLACK)
{

}

template<typename T>
tree<T>::node::node(const_reference val, Color color, pnode nil) :
    val(val),
    left(nil), right(nil), parent(nil),
    color(color)
{}
