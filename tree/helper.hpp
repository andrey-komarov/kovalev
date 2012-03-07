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
auto tree<T>::helper::rotate_right(const pnode& t) -> pnode
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
auto tree<T>::helper::rotate_left(const pnode& t) -> pnode
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
auto tree<T>::helper::grandparent(const pnode& n) const -> pnode
{
    if (n != nil && parent(n) != nil)
        return parent(parent(n));
    return nil;
}

template<typename T>
auto tree<T>::helper::uncle(const pnode& n) const -> pnode
{
    auto g = grandparent(n);
    if (g == nil)
        return nil;
    if (parent(n) == left(g))
        return right(g);
    else
        return left(g);
}

template<typename T>
auto tree<T>::helper::brother(const pnode& n) const -> pnode
{
    if (n == left(parent(n)))
        return right(parent(n));
    else
        return left(parent(n));
}

template<typename T>
auto tree<T>::helper::color(const pnode& t) const -> typename node::Color
{
    return t->color;
}

template<typename T>
auto tree<T>::helper::insert_case1(const pnode& n) -> pnode
{
    if (parent(n) == nil)
    {
        n->color = tree<T>::node::Color::BLACK;
        return n;
    }
    else
        return insert_case2(n);
}

template<typename T>
auto tree<T>::helper::insert_case2(const pnode& n) -> pnode
{
    if (color(parent(n)) == tree<T>::node::Color::BLACK)
        return n;
    else
        return insert_case3(n);
}

template<typename T>
auto tree<T>::helper::insert_case3(const pnode& n) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto u(uncle(n));
    if (u != nil && u->color == Color::RED)
    {
        parent(n)->color = Color::BLACK;
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
auto tree<T>::helper::insert_case4(const pnode& n) -> pnode
{
    auto g = grandparent(n);
    if (n == right(parent(n)) && parent(n) == left(g))
    {
        return insert_case5(left(rotate_left(parent(n)))); // я сам не очень понимаю. сейчас шесть утра и я хочу спать. но это работает
    }                                                      // пожалуйста, не бейте меня за такой код.
    else if (n == left(parent(n)) && parent(n) == right(g))
        return insert_case5(right(rotate_right(parent(n)))); // аналогично, тут
    else
        return insert_case5(n);
}

template<typename T>
auto tree<T>::helper::insert_case5(const pnode& n) -> pnode
{
    typedef typename tree<T>::node::Color Color;

    auto g = grandparent(n);
    n->parent->color = Color::BLACK;
    g->color = Color::RED;
    if (n == left(parent(n)) && parent(n) == left(g))
        return rotate_right(g);
    else
        return rotate_left(g);
}

template<typename T>
auto tree<T>::helper::delete_case1(const pnode& t) -> pnode
{
    if (parent(t) != nil)
        return delete_case2(t);
    t->color = node::Color::BLACK;
    return t;
}

template<typename T>
auto tree<T>::helper::delete_case2(const pnode& t) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother(t);
    if (color(s) == Color::RED)
    {
        parent(t)->color = Color::RED;
        s->color = Color::BLACK;
        if (t == left(parent(t)))
            rotate_left(parent(t));
        else
            rotate_right(parent(t));
    }
    return delete_case3(t);
}

template<typename T>
auto tree<T>::helper::delete_case3(const pnode& t) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    const auto BLACK = Color::BLACK;
    auto s = brother(t);
    if (color(parent(t)) == BLACK && color(s) == BLACK && color(left(s)) == BLACK && color(right(s)) == BLACK)
    {
        s->color = Color::RED;
        return delete_case1(parent(t));
    }
    else
        return delete_case4(t);
}

template<typename T>
auto tree<T>::helper::delete_case4(const pnode& t) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother(t);
    if (color(parent(t)) == Color::RED &&
            color(s) == Color::BLACK &&
    color(left(s)) == Color::BLACK &&
            color(right(s)) == Color::BLACK)
    {
        s->color = Color::RED;
        parent(t)->color = Color::BLACK;
        return t;
    }
    else
        return delete_case5(t);
}

template<typename T>
auto tree<T>::helper::delete_case5(const pnode& t) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother(t);
    if (color(s) == Color::BLACK)
    {
        if (t == left(parent(t)) &&
                color(right(s)) == Color::BLACK &&
        color(left(s)) == Color::RED)
        {
            s->color = Color::RED;
            left(s)->color = Color::BLACK;
            rotate_right(s);
        }
        else if (t == right(parent(t)) &&
        color(left(s)) == Color::BLACK &&
                 color(right(s)) == Color::RED)
        {
            s->color = Color::RED;
            right(s)->color = Color::BLACK;
            rotate_left(s);
        }
    }
    return delete_case6(t);
}

template<typename T>
auto tree<T>::helper::delete_case6(const pnode& t) -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother(t);
    s->color = parent(t)->color;
    t->parent->color = Color::BLACK;
    if (t == left(parent(t)))
    {
        right(s)->color = Color::BLACK;
        return rotate_left(parent(t));
    }
    else
    {
        left(s)->color = Color::BLACK;
        return rotate_right(parent(t));
    }
}

template<typename T>
auto tree<T>::helper::insert(pnode t, const_reference val, pnode& parent) -> pnode
{
    if (t == nil)
    {
        typedef typename tree<T>::node node;
        t = pnode(new node(val, node::Color::RED, nil, nil, parent));
        fixit_insert = t;
        return t;
    }
    if (val < t->val)
    {
        // Очень плохой код. Ничего не понятно. Простите меня
        pnode tmp = insert(left(t), val, t);
        pnode tmp2 = set_parent(tmp, t);
        t = set_left(t, tmp2);
        return t;
    }
    else
    {
        pnode tmp = insert(right(t), val, t);
        pnode tmp2 = set_parent(tmp, t);
        t = set_right(t, tmp2);
        return t;
    }
}


template<typename T>
auto tree<T>::helper::erase(pnode t) -> pnode
{
    typedef typename tree<T>::pnode pnode;
    typedef typename tree<T>::node::Color Color;
    pnode y; // то, что хотим удалять. у него ноль-один сын
    if (left(t) == nil || right(t) == nil)
        y = t;
    else
    {
        y = right(t);
        while (left(y) != nil)
            y = left(y);
    }
    pnode x;
    if (left(y) != nil)
        x = left(y);
    else
        x = right(y);
    x = set_parent(x, parent(y));
    if (parent(y) == nil)
    {
        need_delete_fixup = true;
        fixit_delete = x;
        return x;
    }
    else if (y == left(parent(y)))
        y = set_parent(y, set_left(parent(y), x));
    else
        y = set_parent(y, set_right(parent(y), x));
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
        return erase(left(t), val);
    else
        return erase(right(t), val);
}

template<typename T>
size_t tree<T>::helper::count(const pnode& t, const_reference val) const
{
    if (t == nil)
        return 0;
    if (t->val == val)
        return 1;
    else if (val < t->val)
        return count(left(t), val);
    else
        return count(right(t), val);
}

template<typename T>
size_t tree<T>::helper::depth(const pnode& t) const
{
    if (t == nil)
        return 0;
    return std::max(depth(left(t)), depth(right(t))) + 1;
}

template<typename T>
void tree<T>::helper::insert(const_reference val)
{
// Accept similar elements
//    if (count(val) != 0)
//        return;
    root = insert(root, val, nil);
    if (fixit_insert != nil)
    {
        root = insert_case1(fixit_insert);
        fixit_insert = nil;
    }
    while (parent(root) != nil)
        root = parent(root);
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
    while (parent(root) != nil)
        root = parent(root);
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
        now = left(now);
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
        assert (left(t)->color == Color::BLACK);
        assert (right(t)->color == Color::BLACK);
    }
    depth += t->color == Color::BLACK ? 1 : 0;
    check_black_depth(left(t), depth_need, depth);
    check_black_depth(right(t), depth_need, depth);
}

template<typename T>
auto tree<T>::helper::begin() -> iterator
{
    return begin(revision);
}

template<typename T>
auto tree<T>::helper::begin(size_t revision) -> iterator
{
    pnode first = root;
    if (first == nil)
        return end();
    while (left(first) != nil)
    {
        first = left(first);
    }
    return iterator(t, first, revision);
}

template<typename T>
auto tree<T>::helper::end() -> iterator
{
    return iterator(t, nil, 0);
}

template<typename T>
auto tree<T>::helper::left(const pnode& t, size_t revision) const -> pnode
{
    if (t->patch != nullptr && t->patch->what == patch::What::LEFT && t->patch->revision <= revision)
        return t->patch->new_;
    return t->left_;
}

template<typename T>
auto tree<T>::helper::left(const pnode& t) const -> pnode
{
    return left(t, revision);
}

template<typename T>
auto tree<T>::helper::right(const pnode& t, size_t revision) const -> pnode
{
    if (t->patch != nullptr && t->patch->what == patch::What::RIGHT && t->patch->revision < revision)
        return t->patch->new_;
    return t->right_;
}

template<typename T>
auto tree<T>::helper::right(const pnode& t) const -> pnode
{
    return right(t, revision);
}

template<typename T>
auto tree<T>::helper::parent(const pnode& t, size_t revision) const -> pnode
{
    if (t->patch != nullptr && t->patch->what == patch::What::PARENT && t->patch->revision < revision)
        return t->patch->new_;
    return t->parent;
}

template<typename T>
auto tree<T>::helper::parent(const pnode& t) const -> pnode
{
    return parent(t, revision);
}

template<typename T>
auto tree<T>::helper::set_left(const pnode& t, const pnode& left_) -> pnode
{
    if (left(t) == left_)
        return t;
    if (t->patch == nullptr)
    {
        t->patch = ppatch(new patch(patch::What::LEFT, left_, revision++));
        return t;
    }
    else
    {
        revision++;
        return t->apply();
    }
    t->left_ = left_;
    return t;
}

template<typename T>
auto tree<T>::helper::set_right(const pnode& t, const pnode& right_) -> pnode
{
    if (right(t) == right_)
        return t;
    if (t->patch == nullptr)
    {
        t->patch = ppatch(new patch(patch::What::RIGHT, right_, revision++));
        return t;
    }
    else
    {
        revision++;
        return t->apply();
    }
}

template<typename T>
auto tree<T>::helper::set_parent(const pnode& t, const pnode& parent_) -> pnode
{
    if (parent(t) == parent_)
        return t;
    if (t->patch == nullptr)
    {
        t->patch = ppatch(new patch(patch::What::PARENT, parent_, revision++));
        return t;
    }
    else
    {
        revision++;
        return t->apply();
    }
}

template<typename T>
void tree<T>::helper::tag_it(size_t rev)
{
    roots[rev] = make_pair(revision, root);
}
