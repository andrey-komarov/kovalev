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
    if (n->right != nil)
    {
        n = n->right;
        while (n->left != nil)
            n = n->left;
        return *this;
    }
    while (true)
    {
        if (n->parent == nil)
            return *this = t->end();
        if (n == n->parent->left)
        {
            n = n->parent;
            return *this;
        }
        n = n->parent;
    }
}

template<typename T>
auto tree<T>::iterator::operator++(int) -> iterator
{
    iterator it = *this;
    operator++();
    return it;
}
