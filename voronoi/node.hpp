#include "node.h"

template<typename T>
skiplist<T>::node::node(size_t depth, const T& value) :
    value(value),
    backward(depth, wpnode()),
    forward(depth, pnode())
{}
