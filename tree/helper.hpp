#include "helper.h"

template<typename T>
tree<T>::helper::helper(tree<T>* t) :
    nil(new node()),
    root(nil),
    fixit_insert(nil),
    fixit_delete(nil),
    need_delete_fixup(false),
    revision(0),
t(t)
{}


template<typename T>
auto tree<T>::helper::rotate_right(pnode& t) -> pnode
{
/*      n           A
 *     / \         / \
 *    A   c  ==>  a   n
 *   / \             / \
 *  a   b           b   c */
    auto n = t;
    auto A = left(n);
    n = set_left(n, right(A));
    if (left(n) != nil)
        n = set_left(n, set_parent(left(n), n));
    A = set_right(A, n);
    A = set_parent(A, parent(n));
    n = set_parent(n, A);
    if (parent(A) != nil)
    {
        if (n == left(parent(A)))
            A = set_parent(A, set_left(parent(A), A));
        else
            A = set_parent(A, set_right(parent(A), A));
    }
    return A;
}

template<typename T>
auto tree<T>::helper::rotate_left(pnode& t) -> pnode
{
/*    n               A
 *   / \             / \
 *  a   A    ==>    n   c
 *     / \         / \
 *    b   c       a   b     */
    auto n = t;
    auto A = right(n);
    n = set_right(n, left(A));
    if (right(n) != nil)
        n = set_right(n, set_parent(right(n), n));
    A = set_left(A, n);
    A = set_parent(A, parent(n));
    n = set_parent(n, A);
    if (parent(A) != nil)
    {
        if (n == left(parent(A)))
            A = set_parent(A, set_left(parent(A), A));
        else
            A = set_parent(A, set_right(parent(A), A));
    }
    return A;
}

template<typename T>
auto tree<T>::helper::grandparent(const pnode& n) -> pnode
{
    if (n != nil && n->parent != nil)
        return n->parent->parent;
    return nil;
}

template<typename T>
auto tree<T>::helper::uncle(const pnode& n) -> pnode
{
    auto g = grandparent(n);
    if (g == nil)
        return nil;
    if (n->parent == g->left())
        return g->right();
    else
        return g->left();
}

template<typename T>
auto tree<T>::helper::brother(const pnode& n) -> pnode
{
    if (n == n->parent->left())
        return n->parent->right();
    else
        return n->parent->left();
}

template<typename T>
auto tree<T>::helper::color(const pnode& t) -> typename node::Color
{
    return t->color;
}

template<typename T>
auto tree<T>::helper::insert_case1(pnode n) -> pnode
{
    if (n->parent == nil)
    {
        n->color = tree<T>::node::Color::BLACK;
        return n;
    }
    else
        return insert_case2(n);
}

template<typename T>
auto tree<T>::helper::insert_case2(pnode n) -> pnode
{
    if (color(n->parent) == tree<T>::node::Color::BLACK)
        return n;
    else
        return insert_case3(n);
}

template<typename T>
auto tree<T>::helper::insert_case3(pnode n) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto u(uncle(n));
    if (u != nil && u->color == Color::RED)
    {
        n->parent->color = Color::BLACK;
        u->color = Color::BLACK;
        auto g(grandparent(n));
        g->color = Color::RED;
        return insert_case1(g);
    }
    else
    {
        return insert_case4(n);
    }
}

template<typename T>
auto tree<T>::helper::insert_case4(pnode n) -> pnode
{
    auto g = grandparent(n);
    if (n == n->parent->right() && n->parent == g->left())
    {
        n = rotate_left(n->parent);
        return insert_case5(n->left());
    }
    else if (n == n->parent->left() && n->parent == g->right())
    {
        n = rotate_right(n->parent);
        return insert_case5(n->right());
    }
    else
        return insert_case5(n);
}

template<typename T>
auto tree<T>::helper::insert_case5(pnode n) -> pnode
{
    typedef typename tree<T>::node::Color Color;

    auto g = grandparent(n);
    n->parent->color = Color::BLACK;
    g->color = Color::RED;
    if (n == n->parent->left() && n->parent == g->left())
        return rotate_right(g);
    else
        return rotate_left(g);
}

template<typename T>
auto tree<T>::helper::delete_case1(pnode t) -> pnode
{
    if (t->parent != nil)
        return delete_case2(t);
    t->color = node::Color::BLACK;
    return t;
}

template<typename T>
auto tree<T>::helper::delete_case2(pnode t) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother(t);
    if (color(s) == Color::RED)
    {
        t->parent->color = Color::RED;
        s->color = Color::BLACK;
        if (t == t->parent->left())
            rotate_left(t->parent);
        else
            rotate_right(t->parent);
    }
    return delete_case3(t);
}

template<typename T>
auto tree<T>::helper::delete_case3(pnode t) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    const auto BLACK = Color::BLACK;
    auto s = brother(t);
    if (color(t->parent) == BLACK && color(s) == BLACK && color(s->left()) == BLACK && color(s->right()) == BLACK)
    {
        s->color = Color::RED;
        return delete_case1(t->parent);
    }
    else
        return delete_case4(t);
}

template<typename T>
auto tree<T>::helper::delete_case4(pnode t) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother(t);
    if (color(t->parent) == Color::RED &&
            color(s) == Color::BLACK &&
    color(s->left()) == Color::BLACK &&
            color(s->right()) == Color::BLACK)
    {
        s->color = Color::RED;
        t->parent->color = Color::BLACK;
        return t;
    }
    else
        return delete_case5(t);
}

template<typename T>
auto tree<T>::helper::delete_case5(pnode t) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother(t);
    if (s->color == Color::BLACK)
    {
        if (t == t->parent->left() &&
                color(s->right()) == Color::BLACK &&
        color(s->left()) == Color::RED)
        {
            s->color = Color::RED;
            s->left()->color = Color::BLACK;
            rotate_right(s);
        }
        else if (t == t->parent->right() &&
        color(s->left()) == Color::BLACK &&
                 color(s->right()) == Color::RED)
        {
            s->color = Color::RED;
            s->right()->color = Color::BLACK;
            rotate_left(s);
        }
    }
    return delete_case6(t);
}

template<typename T>
auto tree<T>::helper::delete_case6(pnode t) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother(t);
    s->color = t->parent->color;
    t->parent->color = Color::BLACK;
    if (t == t->parent->left())
    {
        s->right()->color = Color::BLACK;
        return rotate_left(t->parent);
    }
    else
    {
        s->left()->color = Color::BLACK;
        return rotate_right(t->parent);
    }
}

template<typename T>
auto tree<T>::helper::insert(pnode t, const_reference val, const pnode& parent) -> pnode
{
    if (t == nil)
    {
        typedef typename tree<T>::node node;
        t = pnode(new node(val, node::Color::RED, nil));
        t->parent = parent;
        fixit_insert = t;
        return t;
    }
// Accept similar elements
//    if (t->val == val)
//        return t;
    if (val < t->val)
    {
        t->left() = insert(t->left(), val, t);
        t->left()->parent = t;
        return t;
    }
    else
    {
        t->right() = insert(t->right(), val, t);
        t->right()->parent = t;
        return t;
    }
}


template<typename T>
auto tree<T>::helper::erase(pnode t) -> pnode
{
    typedef typename tree<T>::pnode pnode;
    typedef typename tree<T>::node::Color Color;
    pnode y; // то, что хотим удалять. у него ноль-один сын
    if (t->left() == nil || t->right() == nil)
        y = t;
    else
    {
        y = t->right();
        while (y->left() != nil)
            y = y->left();
    }
    pnode x;
    if (y->left() != nil)
        x = y->left();
    else
        x = y->right();
    x->parent = y->parent;
    if (y->parent == nil)
    {
        need_delete_fixup = true;
        fixit_delete = x;
        return x;
    }
    else if (y == y->parent->left())
        y->parent->left() = x;
    else
        y->parent->right() = x;
    if (y != t)
        t->val = y->val;
    if (y->color == Color::BLACK)
    {
        need_delete_fixup = true;
        fixit_delete = x;
    }
    return y;
}

template<typename T>
auto tree<T>::helper::erase(pnode t, const_reference val) -> pnode
{
    if (t == nil)
        return t;
    if (t->val == val)
        return erase(t);
    else if (val < t->val)
        return erase(t->left(), val);
    else
        return erase(t->right(), val);
}

template<typename T>
size_t tree<T>::helper::count(const pnode& t, const_reference val) const
{
    if (t == nil)
        return 0;
    if (t->val == val)
        return 1;
    else if (val < t->val)
        return count(t->left(), val);
    else
        return count(t->right(), val);
}

template<typename T>
size_t tree<T>::helper::depth(const pnode& t) const
{
    if (t == nil)
        return 0;
    return std::max(depth(t->left()), depth(t->right())) + 1;
}

template<typename T>
void tree<T>::helper::insert(const_reference val)
{
//    if (count(val) != 0)
//        return;
    root = insert(root, val, nil);
    if (fixit_insert != nil)
    {
        insert_case1(fixit_insert);
        fixit_insert = nil;
    }
    while (root->parent != nil)
        root = root->parent;
}

template<typename T>
void tree<T>::helper::erase(const_reference val)
{
    if (count(val) == 0)
        return;
    root = erase(root, val);
    if (need_delete_fixup)
    {
        delete_case1(fixit_delete);
        need_delete_fixup = false;
    }
    while (root->parent != nil)
        root = root->parent;
}

template<typename T>
size_t tree<T>::helper::count(const_reference val) const
{
    return count(root, val);
}

template<typename T>
size_t tree<T>::helper::depth() const
{
    return depth(root);
}

template<typename T>
void tree<T>::helper::check_rb_properties() const
{
    typedef typename node::Color Color;
    assert (root->color == Color::BLACK);
    pnode now = root;
    size_t black_depth(0);
    while (now != nil)
    {
        black_depth += now->color == Color::BLACK ? 1 : 0;
        now = now->left();
    }
    check_black_depth(root, black_depth);
}

template<typename T>
void tree<T>::helper::check_black_depth(const pnode& t, size_t depth_need, size_t depth) const
{
    if (t == nil)
    {
        assert (depth_need == depth);
        return;
    }

    typedef typename tree<T>::node::Color Color;
    if (t->color == Color::RED)
    {
        assert (t->left()->color == Color::BLACK);
        assert (t->right()->color == Color::BLACK);
    }
    depth += t->color == Color::BLACK ? 1 : 0;
    check_black_depth(t->left(), depth_need, depth);
    check_black_depth(t->right(), depth_need, depth);
}

template<typename T>
auto tree<T>::helper::begin() -> iterator
{
    pnode first = root;
    if (first == nil)
        return end();
    while (first->left() != nil)
    {
        first = first->left();
    }
    return iterator(t, first);
}

template<typename T>
auto tree<T>::helper::end() -> iterator
{
    return iterator(t, nil);
}


template<typename T>
auto tree<T>::helper::left(pnode& t) -> pnode&
{
    return t->left_;
}

template<typename T>
auto tree<T>::helper::right(pnode& t) -> pnode&
{
    return t->right_;
}

template<typename T>
auto tree<T>::helper::parent(pnode& t) -> pnode&
{
    return t->parent;
}

template<typename T>
auto tree<T>::helper::set_left(pnode& t, pnode& left) -> pnode&
{
    t->left_ = left;
    return t;
}

template<typename T>
auto tree<T>::helper::set_right(pnode& t, pnode& right) -> pnode&
{
    t->right_ = right;
    return t;
}

template<typename T>
auto tree<T>::helper::set_parent(pnode& t, pnode& parent) -> pnode&
{
    t->parent = parent;
    return t;
}
