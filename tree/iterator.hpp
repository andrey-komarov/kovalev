template<typename T>
tree<T>::iterator::iterator(tree<T>* t, typename tree<T>::pnode n) :
    t(t), n(n)
{}

template<typename T>
typename tree<T>::iterator& tree<T>::iterator::operator=(const typename tree<T>::iterator& it)
{
    t = it.t;
    n = it.n;
    return *this;
}

template<typename T>
typename tree<T>::iterator tree<T>::begin()
{
    pnode first = root;
    if (first == nil<T>())
        return end();
    while (first->left != nil<T>())
    {
        first = first->left;
    }
    return iterator(this, first);
}

template<typename T>
typename tree<T>::iterator tree<T>::end()
{
    return iterator(this, nil<T>());
}

template<typename T>
typename tree<T>::const_reference tree<T>::iterator::operator*()
{
    return n->val;
}

template<typename T>
bool tree<T>::iterator::operator==(const typename tree<T>::iterator& it) const
{
    return t == it.t && n == it.n;
}

template<typename T>
bool tree<T>::iterator::operator!=(const typename tree<T>::iterator& it) const
{
    return !operator==(it);
}

template<typename T>
typename tree<T>::iterator& tree<T>::iterator::operator++()
{
    if (n->right != nil<T>())
    {
        n = n->right;
        while (n->left != nil<T>())
            n = n->left;
        return *this;
    }
    while (true)
    {
        if (n->parent == nil<T>())
            return *this = t->end();
        if (n == n->parent->left)
        {
            n = n->parent;
            return *this;
        }
        n = n->parent;
    }
}
