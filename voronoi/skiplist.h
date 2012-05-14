#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <memory>

template<typename T>
struct skiplist
{
    struct iterator;
    skiplist();
    void insert(const iterator& it, const T& value);
    void remove(const iterator& it);

    iterator begin();
    iterator end();
private:
    static const size_t MAX_DEPTH = 50;

    struct node;
    typedef std::shared_ptr<node> pnode;
    typedef std::weak_ptr<node> wpnode;

    pnode zero, inf;


    template<typename Pred>
    friend
    typename skiplist<T>::iterator lower_bound(const skiplist<T>& list, const Pred& p);
};

template<typename T, typename Pred>
typename skiplist<T>::iterator lower_bound(const skiplist<T>& list, const Pred& p);

#include "skiplist.hpp"
#include "node.h"
#include "iterator.h"

#endif // SKIPLIST_H
