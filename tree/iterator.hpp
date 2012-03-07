template<typename T>
tree<T>::iterator::iterator(tree<T>* t, typename tree<T>::pnode n) :
    t(t), n(n)
{}

template<typename T>
auto tree<T>::iterator::operator=(const iterator& it) -> iterator&
{
    t = it.t;
    n = it.n;
    return *this;
}

template<typename T>
auto tree<T>::iterator::operator*() -> const_reference
{
    return n->val;
}

template<typename T>
auto tree<T>::iterator::operator->() -> pointer
{
    return *(n->val);
}

template<typename T>
bool tree<T>::iterator::operator==(const iterator& it) const
{
    return t == it.t && n == it.n;
}

template<typename T>
bool tree<T>::iterator::operator!=(const iterator& it) const
{
    return !operator==(it);
}

template<typename T>
auto tree<T>::iterator::operator++() -> iterator&
{
    pnode& nil = t->h.nil;
    if (t->h.right(n) != nil)
    {
        n = t->h.right(n);
        while (t->h.left(n) != nil)
            n = t->h.left(n);
        return *this;
    }
    while (true)
    {
        if (t->h.parent(n) == nil)
            return *this = t->end();
        if (n == t->h.left(t->h.parent(n)))
        {
            n = t->h.parent(n);
            return *this;
        }
        n = t->h.parent(n);
    }
}

template<typename T>
auto tree<T>::iterator::operator++(int) -> iterator
{
    iterator it = *this;
    operator++();
    return it;
}
