template<typename T>
typename tree<T>::pnode insert_case1(typename tree<T>::pnode);
template<typename T>
typename tree<T>::pnode insert_case2(typename tree<T>::pnode);
template<typename T>
typename tree<T>::pnode insert_case3(typename tree<T>::pnode);
template<typename T>
typename tree<T>::pnode insert_case4(typename tree<T>::pnode);
template<typename T>
typename tree<T>::pnode insert_case5(typename tree<T>::pnode);
template<typename T>
typename tree<T>::pnode rotate_left(typename tree<T>::pnode&);
template<typename T>
typename tree<T>::pnode rotate_right(typename tree<T>::pnode&);
template<typename T>
typename tree<T>::pnode grandparent(const typename tree<T>::pnode&);
template<typename T>
typename tree<T>::pnode uncle(const typename tree<T>::pnode& n);
template<typename T>
typename tree<T>::pnode brother(const typename tree<T>::pnode& n);
template<typename T>
//typename tree<T>::pnode delete_one_child(typename tree<T>::pnode&);
//template<typename T>
typename tree<T>::pnode delete_case1(typename tree<T>::pnode);
template<typename T>
typename tree<T>::pnode delete_case2(typename tree<T>::pnode);
template<typename T>
typename tree<T>::pnode delete_case3(typename tree<T>::pnode);
template<typename T>
typename tree<T>::pnode delete_case4(typename tree<T>::pnode);
template<typename T>
typename tree<T>::pnode delete_case5(typename tree<T>::pnode);
template<typename T>
typename tree<T>::pnode delete_case6(typename tree<T>::pnode);
template<typename T>
typename tree<T>::node::Color color(const typename tree<T>::pnode&);

template<typename T>
typename tree<T>::pnode& nil()
{
    static typename tree<T>::pnode nil_(new typename tree<T>::node());
    return nil_;
}

template<typename T>
typename tree<T>::pnode& fixit_insert()
{
    static typename tree<T>::pnode fixit_insert_(nil<T>());
    return fixit_insert_;
}

template<typename T>
typename tree<T>::pnode& fixit_delete()
{
    static typename tree<T>::pnode fixit_delete_(nil<T>());
    return fixit_delete_;
}

template<typename T>
typename tree<T>::pnode rotate_right(typename tree<T>::pnode& t)
{
/*      n           A
 *     / \         / \
 *    A   c  ==>  a   n
 *   / \             / \
 *  a   b           b   c */
    typename tree<T>::pnode n = t;
    auto A = n->left;
    n->left = A->right;
    if (n->left != nil<T>())
        n->left->parent = n;
    A->right = n;
    A->parent = n->parent;
    n->parent = A;
    if (A->parent != nil<T>())
        ((n == A->parent->left) ? A->parent->left : A->parent->right) = A;
    return A;
}

template<typename T>
typename tree<T>::pnode rotate_left(typename tree<T>::pnode& t)
{
/*    n               A
 *   / \             / \
 *  a   A    ==>    n   c
 *     / \         / \
 *    b   c       a   b     */
    typename tree<T>::pnode n = t;
    auto A = n->right;
    n->right = A->left;
    if (n->right != nil<T>())
        n->right->parent = n;
    A->left = n;
    A->parent = n->parent;
    n->parent = A;
    if (A->parent != nil<T>())
        ((n == A->parent->left) ? A->parent->left : A->parent->right) = A;
    return A;
}

template<typename T>
typename tree<T>::pnode grandparent(const typename tree<T>::pnode& n)
{
    if (n != nil<T>() && n->parent != nil<T>())
        return n->parent->parent;
    return nil<T>();
}

template<typename T>
typename tree<T>::pnode uncle(const typename tree<T>::pnode& n)
{
    const typename tree<T>::pnode g = grandparent<T>(n);
    if (g == nil<T>())
        return nil<T>();
    if (n->parent == g->left)
        return g->right;
    else
        return g->left;
}

template<typename T>
typename tree<T>::pnode brother(const typename tree<T>::pnode& n)
{
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}

template<typename T>
typename tree<T>::node::Color color(const typename tree<T>::pnode& t)
{
    return t->color;
}

template<typename T>
typename tree<T>::pnode insert_case1(typename tree<T>::pnode n)
{
    if (n->parent == nil<T>())
    {
        n->color = tree<T>::node::Color::BLACK;
        return n;
    }
    else
        return insert_case2<T>(n);
}

template<typename T>
typename tree<T>::pnode insert_case2(typename tree<T>::pnode n)
{
    if (color<T>(n->parent) == tree<T>::node::Color::BLACK)
        return n;
    else
        return insert_case3<T>(n);
}

template<typename T>
typename tree<T>::pnode insert_case3(typename tree<T>::pnode n)
{
    typedef typename tree<T>::node::Color Color;
    auto u(uncle<T>(n));
    if (u != nil<T>() && u->color == Color::RED)
    {
        n->parent->color = Color::BLACK;
        u->color = Color::BLACK;
        auto g(grandparent<T>(n));
        g->color = Color::RED;
        return insert_case1<T>(g);
    }
    else
    {
        return insert_case4<T>(n);
    }

}

template<typename T>
typename tree<T>::pnode insert_case4(typename tree<T>::pnode n)
{
    auto g = grandparent<T>(n);
    if (n == n->parent->right && n->parent == g->left)
    {
        n = rotate_left<T>(n->parent);
        return insert_case5<T>(n->left);
    }
    else if (n == n->parent->left && n->parent == g->right)
    {
        n = rotate_right<T>(n->parent);
        return insert_case5<T>(n->right);
    }
    else
        return insert_case5<T>(n);
}

template<typename T>
typename tree<T>::pnode insert_case5(typename tree<T>::pnode n)
{
    typedef typename tree<T>::node::Color Color;

    auto g = grandparent<T>(n);
    n->parent->color = Color::BLACK;
    g->color = Color::RED;
    if (n == n->parent->left && n->parent == g->left)
        return rotate_right<T>(g);
    else
        return rotate_left<T>(g);
}

template<typename T>
typename tree<T>::pnode tree<T>::node::insert(typename tree<T>::pnode t, typename tree<T>::const_reference val, const typename tree<T>::pnode& parent)
{
    if (t == nil<T>())
    {
        typedef typename tree<T>::node node;
        t = pnode(new node(val, node::Color::RED));
        t->parent = parent;
        fixit_insert<T>() = t;
        return t;
    }
    if (t->val == val)
        return t;
    if (val < t->val)
    {
        t->left = insert(t->left, val, t);
        t->left->parent = t;
        return t;
    }
    else
    {
        t->right = insert(t->right, val, t);
        t->right->parent = t;
        return t;
    }
}

//template<typename T>
//typename tree<T>::pnode delete_one_child(typename tree<T>::pnode& t)
//{
//    typedef typename tree<T>::node::Color Color;
//    typename tree<T>::pnode c = t->left == nil<T>() ? t->right : t->left;
//    auto t_old = t;
//    if (c == nil<T>())
//    {
//        t->parent->left = nil<T>();
//        t->parent->right = nil<T>();
//        t = nil<T>();
//        if (color<T>(t) == Color::BLACK)
//            delete_case1<T>(t_old->parent);
//        return;
//    }
//    t = c;
//    if (color<T>(t_old) == Color::BLACK)
//    {
//        if (color<T>(c) == Color::RED)
//            c->color = Color::BLACK;
//        else
//            delete_case1<T>(c == nil<T>() ? t_old->parent : c);
//    }
//}

template<typename T>
typename tree<T>::pnode delete_case1(typename tree<T>::pnode t)
{
    if (t->parent != nil<T>())
        return delete_case2<T>(t);
    return t;
}

template<typename T>
typename tree<T>::pnode delete_case2(typename tree<T>::pnode t)
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother<T>(t);
    if (color<T>(s) == Color::RED)
    {
        t->parent->color = Color::RED;
        s->color = Color::BLACK;
        if (t == t->parent->left)
            rotate_left<T>(t->parent);
        else
            rotate_right<T>(t->parent);
    }
    return delete_case3<T>(t);
}

template<typename T>
typename tree<T>::pnode delete_case3(typename tree<T>::pnode t)
{
    typedef typename tree<T>::node::Color Color;
    const auto BLACK = Color::BLACK;
    auto s = brother<T>(t);
    if (color<T>(t->parent) == BLACK && color<T>(s) == BLACK && color<T>(s->left) == BLACK && color<T>(s->right) == BLACK)
    {
        s->color = Color::RED;
        return delete_case1<T>(t->parent);
    }
    else
        return delete_case4<T>(t);
}

template<typename T>
typename tree<T>::pnode delete_case4(typename tree<T>::pnode t)
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother<T>(t);
    if (color<T>(t->parent) == Color::RED &&
            color<T>(s) == Color::BLACK &&
            color<T>(s->left) == Color::BLACK &&
            color<T>(s->right) == Color::BLACK)
    {
        s->color = Color::RED;
        t->parent->color = Color::BLACK;
        return t;
    }
    else
        return delete_case5<T>(t);
}

template<typename T>
typename tree<T>::pnode delete_case5(typename tree<T>::pnode t)
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother<T>(t);
    if (s->color == Color::BLACK)
    {
        if (t == t->parent->left &&
                color<T>(s->right) == Color::BLACK &&
                color<T>(s->left) == Color::RED)
        {
            s->color = Color::RED;
            s->left->color = Color::BLACK;
            rotate_right<T>(s);
        }
        else if (t == t->parent->right &&
                 color<T>(s->left) == Color::BLACK &&
                 color<T>(s->right) == Color::RED)
        {
            s->color = Color::RED;
            s->right->color = Color::BLACK;
            rotate_left<T>(s);
        }
    }
    return delete_case6<T>(t);
}

template<typename T>
typename tree<T>::pnode delete_case6(typename tree<T>::pnode t)
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother<T>(t);
    s->color = t->parent->color;
    t->parent->color = Color::BLACK;
    if (t == t->parent->left)
    {
        s->right->color = Color::BLACK;
        return rotate_left<T>(t->parent);
    }
    else
    {
        s->left->color = Color::BLACK;
        return rotate_right<T>(t->parent);
    }
}

template<typename T>
typename tree<T>::pnode tree<T>::node::erase(typename tree<T>::pnode t, tree<T>::const_reference val)
{
    if (t == nil<T>())
        return t;
    if (t->val == val)
        return erase(t);
    else if (val < t->val)
        return erase(t->left, val);
    else
        return erase(t->right, val);
}

template<typename T>
size_t tree<T>::node::count(typename tree<T>::pnode& t, typename tree<T>::const_reference val)
{
    if (t == nil<T>())
        return 0;
    if (t->val == val)
        return 1;
    else if (val < t->val)
        return count(t->left, val);
    else
        return count(t->right, val);
}

template<typename T>
typename tree<T>::pnode tree<T>::node::erase(typename tree<T>::pnode t)
{
    typedef typename tree<T>::pnode pnode;
    typedef typename tree<T>::node::Color Color;
    pnode y; // то, что хотим удалять. у него ноль-один сын
    if (t->left == nil<T>()|| t->right == nil<T>())
        y = t;
    else
    {
        y = t->right;
        while (y->left != nil<T>())
            y = y->left;
    }
    pnode x;
    if (y->left != nil<T>())
        x = y->left;
    else
        x = y->right;
    x->parent = y->parent;
    if (y->parent == nil<T>())
    {
        fixit_delete<T>() = nil<T>();
        return x;
    }
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    if (y != t)
        t->val = y->val;
    if (y->color == Color::BLACK)
        fixit_delete<T>() = x;
    return y;
}

template<typename T>
tree<T>::node::node() :
    left(nullptr), right(nullptr), parent(nullptr),
    color(Color::BLACK)
{

}

template<typename T>
tree<T>::node::node(const_reference val, Color color) :
    val(val),
    left(nil<T>()), right(nil<T>()), parent(nil<T>()),
    color(color)
{}

template<typename T>
size_t tree<T>::node::depth(typename tree<T>::pnode& t)
{
    if (t == nil<T>())
        return 0;
    return std::max(depth(t->left), depth(t->right)) + 1;
}
