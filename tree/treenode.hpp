template<typename T>
void insert_case1(typename tree<T>::pnode&);
template<typename T>
void insert_case2(typename tree<T>::pnode&);
template<typename T>
void insert_case3(typename tree<T>::pnode&);
template<typename T>
void insert_case4(typename tree<T>::pnode&);
template<typename T>
void insert_case5(typename tree<T>::pnode&);
template<typename T>
void rotate_left(typename tree<T>::pnode&);
template<typename T>
void rotate_right(typename tree<T>::pnode&);
template<typename T>
typename tree<T>::pnode grandparent(const typename tree<T>::pnode&);
template<typename T>
typename tree<T>::pnode uncle(const typename tree<T>::pnode& n);
template<typename T>
typename tree<T>::pnode brother(const typename tree<T>::pnode& n);
template<typename T>
void delete_one_child(typename tree<T>::pnode&);

template<typename T>
void rotate_right(typename tree<T>::pnode& n)
{
/*      n           A
 *     / \         / \
 *    A   c  ==>  a   n
 *   / \             / \
 *  a   b           b   c */
    typename tree<T>::pnode A = n->left;
    n->left = A->right;
    if (n->left != nullptr)
        n->left->parent = n;
    A->right = n;
    A->parent = n->parent;
    if (A->parent != nullptr)
        (n == A->parent->left ? A->parent->left : A->parent->right) = A;
    if (A->right != nullptr)
        A->right->parent = A;
    n = A;
}

template<typename T>
void rotate_left(typename tree<T>::pnode& n)
{
/*    n               A
 *   / \             / \
 *  a   A    ==>    n   c
 *     / \         / \
 *    b   c       a   b     */
    typename tree<T>::pnode A = n->right;
    n->right = A->left;
    if (n->right != nullptr)
        n->right->parent = n;
    A->left = n;
    A->parent = n->parent;
    if (A->parent != nullptr)
        (n == A->parent->left ? A->parent->left : A->parent->right) = A;
    if (A->left != nullptr)
        A->left->parent = A;
    n = A;
}

template<typename T>
typename tree<T>::pnode grandparent(const typename tree<T>::pnode& n)
{
    if (n != nullptr && n->parent != nullptr)
        return n->parent->parent;
    return nullptr;
}

template<typename T>
typename tree<T>::pnode uncle(const typename tree<T>::pnode& n)
{
    const typename tree<T>::pnode g = grandparent<T>(n);
    if (g == nullptr)
        return nullptr;
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
void insert_case1(typename tree<T>::pnode& n)
{
    if (n->parent == nullptr)
        n->color = tree<T>::node::Color::BLACK;
    else
        insert_case2<T>(n);
}

template<typename T>
void insert_case2(typename tree<T>::pnode& n)
{
    if (n->parent->color == tree<T>::node::Color::BLACK)
        return;
    else
        insert_case3<T>(n);
}

template<typename T>
void insert_case3(typename tree<T>::pnode& n)
{
    typedef typename tree<T>::pnode pnode;
    typedef typename tree<T>::node::Color Color;
    pnode u(uncle<T>(n));
    if (u != nullptr && u->color == Color::RED)
    {
        n->parent->color = Color::BLACK;
        u->color = Color::BLACK;
        pnode g(grandparent<T>(n));
        g->color = Color::RED;
        insert_case1<T>(g);
    }
    else
    {
        insert_case4<T>(n);
    }

}

template<typename T>
void insert_case4(typename tree<T>::pnode& n)
{
    typename tree<T>::pnode g = grandparent<T>(n);
    if (n == n->parent->right && n->parent == g->left)
    {
        rotate_left<T>(n->parent);
        insert_case5<T>(n->left);
    }
    else if (n == n->parent->left && n->parent == g->right)
    {
        rotate_right<T>(n->parent);
        insert_case5<T>(n->right);
    }
    else
        insert_case5<T>(n);
}

template<typename T>
void insert_case5(typename tree<T>::pnode& n)
{
    typedef typename tree<T>::node::Color Color;

    typename tree<T>::pnode g = grandparent<T>(n);
    n->parent->color = Color::BLACK;
    g->color = Color::RED;
    if (n == n->parent->left && n->parent == g->left)
        rotate_right<T>(g);
    else
        rotate_left<T>(g);
}

template<typename T>
void tree<T>::node::insert(typename tree<T>::pnode& t, typename tree<T>::const_reference val, const typename tree<T>::pnode& parent)
{
    if (t == nullptr)
    {
        typedef typename tree<T>::node node;
        t = pnode(new node(val, node::Color::RED));
        t->parent = parent;
        insert_case1<T>(t);
        return;
    }
    if (t->val == val)
        return;
    if (val < t->val)
    {
        insert(t->left, val, t);
    }
    else
    {
        insert(t->right, val, t);
    }
}

template<typename T>
void delete_one_child(typename tree<T>::pnode& t)
{
    assert (t->left == nullptr || t->right == nullptr);
    typename tree<T>::pnode c = t->left == nullptr ? t->right : t->left;

}

template<typename T>
tree<T>::node::node(const_reference val, Color color) :
    val(val),
    left(nullptr), right(nullptr), parent(nullptr),
    color(color)
{}


template<typename T>
size_t tree<T>::node::depth(typename tree<T>::pnode& t)
{
    if (t == nullptr)
        return 0;
    return std::max(depth(t->left), depth(t->right)) + 1;
}
