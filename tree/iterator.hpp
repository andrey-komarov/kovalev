template<typename T>
tree<T>::iterator::iterator(tree<T>* t, size_t rev, const std::vector<pnode>& stack) :
t(t), revision(rev), stack(stack), n(stack.empty() ? nullptr : stack.back())
{}

template<typename T>
auto tree<T>::iterator::operator=(const iterator& it) -> iterator&
{
    t = it.t;
    n = it.n;
    revision = it.revision;
    stack = it.stack;
    return *this;
}

template<typename T>
auto tree<T>::iterator::operator*() -> const_reference
{
    return n->val;
}

//template<typename T>
//auto tree<T>::iterator::operator->() -> pointer
//{
//    return *(n->val);
//}

template<typename T>
bool tree<T>::iterator::operator==(const iterator& it) const
{
    return (revision == it.revision || n == nullptr) && t == it.t && n == it.n;
}

template<typename T>
bool tree<T>::iterator::operator!=(const iterator& it) const
{
    return !operator==(it);
}

template<typename T>
auto tree<T>::iterator::parent() const -> pnode
{
    if (stack.size() < 2)
        return nullptr;
    return stack[stack.size() - 2];
}

template<typename T>
auto tree<T>::iterator::operator++() -> iterator&
{
    if (t->h.right(n, revision) != nullptr)
    {
        n = t->h.right(n, revision);
        stack.push_back(n);
        while (t->h.left(n, revision) != nullptr)
        {
            n = t->h.left(n, revision);
            stack.push_back(n);
        }
        return *this;
    }
    while (true)
    {
        pnode p(parent());
        if (p == nullptr)
            return *this = t->end();
        if (n == t->h.left(p))
        {
            n = p;
            stack.pop_back();
            return *this;
        }
        stack.pop_back();
        n = p;
    }
}

template<typename T>
auto tree<T>::iterator::operator++(int) -> iterator
{
    iterator it = *this;
    operator++();
    return it;
}
