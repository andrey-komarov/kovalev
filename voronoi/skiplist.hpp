#include "skiplist.h"

template<typename T>
skiplist<T>::skiplist() :
    zero(new node(MAX_DEPTH)),
    inf(new node(MAX_DEPTH))
{
    for (size_t i = 0; i < MAX_DEPTH; i++)
    {
        zero->forward[i] = inf;
        inf->backward[i] = zero;
    }
}

template<typename T>
auto skiplist<T>::begin() -> iterator
{
    return iterator(zero->forward[0]);
}

template<typename T>
auto skiplist<T>::end() -> iterator
{
    return iterator(inf);
}

template<typename T>
void skiplist<T>::insert(const iterator &it, const T &value)
{
    size_t depth = 1;
    while (rand() & 1)
        depth++;
    pnode now(new node(depth, value));
    pnode current(it.n.lock());
    for (size_t i = 0; i < depth;)
    {
        if (current->forward.size() > i && i < depth)
        {
            now->forward[i] = current->forward[i];
            now->backward[i] = current;
            now->forward[i]->backward[i] = now;
            now->backward[i].lock()->forward[i] = now;
            i++;
        }
        else
            current = current->backward[i - 1].lock();
    }
}

template<typename T>
void skiplist<T>::remove(const iterator &it)
{
    pnode p = it.n.lock();
    for (size_t i = 0; i < p->forward.size(); i++)
    {
        p->backward[i].lock()->forward[i] = p->forward[i];
        p->forward[i]->backward[i] = p->backward[i];
    }
}

template<typename T>
template<typename Pred>
auto skiplist<T>::lower_bound(const Pred& p) -> iterator
{
    pnode now = zero;
    for (int depth = MAX_DEPTH - 1; depth >= 0; )
    {
        pnode to = now->forward[depth];
        if (to != inf && p(iterator(to)))
            now = to;
        else
            depth--;
    }
    return iterator(now);
}
