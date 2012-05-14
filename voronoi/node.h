#ifndef NODE_H
#define NODE_H

#include "skiplist.h"

#include <vector>

template<typename T>
struct skiplist<T>::node
{
    node(size_t depth, const T& = T());
    T value;
    std::vector<wpnode> backward;
    std::vector<pnode> forward;
};

#include "node.hpp"

#endif // NODE_H
