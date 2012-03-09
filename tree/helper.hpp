#include "helper.h"

template<typename T>
tree<T>::helper::helper(tree<T>* t) :
    nil(new node()),
    root(nil),
    revision_(0),
size_(0),
t(t),
need_delete_fixup(false),
stack()
{}


// в стеке лежит вершина n, вокруг которой крутим. результат кладётся обратно
template<typename T>
auto tree<T>::helper::rotate_right() -> pnode
{
/*      n           A
 *     / \         / \
 *    A   c  ==>  a   n
 *   / \             / \
 *  a   b           b   c */
    auto n = stack.back();
    auto A = left(n);
    pnode new_n(new node(n->val, n->color, right(A), right(n)));
    pnode new_A(new node(A->val, A->color, left(A), new_n));
    replace_stack_top_with(new_A);
    return new_A;
}

template<typename T>
auto tree<T>::helper::rotate_left() -> pnode
{
/*    n               A
 *   / \             / \
 *  a   A    ==>    n   c
 *     / \         / \
 *    b   c       a   b     */
    auto n = stack.back();
    auto A = right(n);
    pnode new_n(new node(n->val, n->color, left(n), left(A)));
    pnode new_A(new node(A->val, A->color, new_n, right(A)));
    replace_stack_top_with(new_A);
    return new_A;
}

//все эти родственники считаются от вершины стека
template<typename T>
auto tree<T>::helper::grandparent() const -> pnode
{
    if (stack.size() <= 2)
        return nil;
    else
        return stack[stack.size() - 3];
}

template<typename T>
auto tree<T>::helper::parent() const -> pnode
{
    if (stack.size() <= 1)
        return nil;
    return stack[stack.size() - 2];
}

template<typename T>
auto tree<T>::helper::uncle() const -> pnode
{
    auto g = grandparent();
    if (g == nil)
        return nil;
    if (parent() == left(g))
        return right(g);
    else
        return left(g);
}

template<typename T>
auto tree<T>::helper::brother() const -> pnode
{
    if (is_left_son())
        return right(parent());
    else
        return left(parent());
}

template<typename T>
auto tree<T>::helper::color(const pnode& t) const -> typename node::Color
{
    return t->color;
}

template<typename T>
bool tree<T>::helper::is_left_son() const
{
    auto p = parent();
    return stack.back() == left(p);
}

template<typename T>
bool tree<T>::helper::is_right_son() const
{
    return !is_left_son();
}

// все эти операции починки запускаются от вершины стека
template<typename T>
auto tree<T>::helper::insert_case1() -> pnode
{
    pnode n = stack.back();
    if (parent() == nil)
    {
        n->color = tree<T>::node::Color::BLACK;
        return stack.back();
    }
    else
        return insert_case2();
}

template<typename T>
auto tree<T>::helper::insert_case2() -> pnode
{
    pnode n = stack.back();
    if (color(parent()) == tree<T>::node::Color::BLACK)
        return n;
    else
        return insert_case3();
}

template<typename T>
auto tree<T>::helper::insert_case3() -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto u(uncle());
    if (u != nil && u->color == Color::RED)
    {
        parent()->color = Color::BLACK;
        u->color = Color::BLACK;
        auto g(grandparent());
        g->color = Color::RED;
        stack.pop_back();
        stack.pop_back();
        return insert_case1();
    }
    else
    {
        return insert_case4();
    }
}

template<typename T>
auto tree<T>::helper::insert_case4() -> pnode
{
    auto g = grandparent();
    auto p = parent();
    if (is_right_son() && p == left(g))
    {
        stack.pop_back();
        rotate_left();
        stack.push_back(left(stack.back()));
        return insert_case5();
    }
    else if (is_left_son() && parent() == right(g))
    {
        stack.pop_back();
        rotate_right();
        stack.push_back(right(stack.back()));
        return insert_case5();
    }
    else
        return insert_case5();
}

template<typename T>
auto tree<T>::helper::insert_case5() -> pnode
{
    typedef typename tree<T>::node::Color Color;

    auto g = grandparent();
    auto p = parent();
    p->color = Color::BLACK;
    g->color = Color::RED;
    if (is_left_son() && p == left(g))
    {
        stack.pop_back();
        stack.pop_back();
        return rotate_right();
    }
    else
    {
        stack.pop_back();
        stack.pop_back();
        return rotate_left();
    }
}

template<typename T>
auto tree<T>::helper::delete_case1() -> pnode
{
    pnode t = stack.back();
    if (parent() != nil)
        return delete_case2();
    t->color = node::Color::BLACK;
    return t;
}

template<typename T>
auto tree<T>::helper::delete_case2() -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother();
    auto p = parent();
    if (color(s) == Color::RED)
    {
        p->color = Color::RED;
        s->color = Color::BLACK;
        if (is_left_son())
        {
            // вот ну что это за хрень?
            stack.pop_back();
            rotate_left();
            stack.push_back(left(stack.back()));
            stack.push_back(left(stack.back()));
        }
        else
        {
            stack.pop_back();
            rotate_right();
            stack.push_back(right(stack.back()));
            stack.push_back(right(stack.back()));
        }
    }
    return delete_case3();
}

template<typename T>
auto tree<T>::helper::delete_case3() -> pnode
{
    typedef typename tree<T>::node::Color Color;
    const auto BLACK = Color::BLACK;
    auto s = brother();
    auto p = parent();
    if (color(p) == BLACK && color(s) == BLACK && color(left(s)) == BLACK && color(right(s)) == BLACK)
    {
        s->color = Color::RED;
        stack.pop_back();
        return delete_case1();
    }
    else
        return delete_case4();
}

template<typename T>
auto tree<T>::helper::delete_case4() -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother();
    auto p = parent();
    if (color(p) == Color::RED &&
            color(s) == Color::BLACK &&
    color(left(s)) == Color::BLACK &&
            color(right(s)) == Color::BLACK)
    {
        s->color = Color::RED;
        p->color = Color::BLACK;
        return stack.back();
    }
    else
        return delete_case5();
}

template<typename T>
auto tree<T>::helper::delete_case5() -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother();
//    auto p = parent();
    if (color(s) == Color::BLACK)
    {
        if (is_left_son() &&
                color(right(s)) == Color::BLACK &&
        color(left(s)) == Color::RED)
        {
            s->color = Color::RED;
            left(s)->color = Color::BLACK;
            stack.pop_back();
            stack.push_back(right(stack.back()));
            rotate_right();
            stack.pop_back();
            stack.push_back(left(stack.back()));
        }
        else if (is_right_son() &&
        color(left(s)) == Color::BLACK &&
                 color(right(s)) == Color::RED)
        {
            s->color = Color::RED;
            right(s)->color = Color::BLACK;
            stack.pop_back();
            stack.push_back(left(stack.back()));
            rotate_left();
            stack.pop_back();
            stack.push_back(right(stack.back()));
        }
    }
    return delete_case6();
}

template<typename T>
auto tree<T>::helper::delete_case6() -> pnode
{
    typedef typename tree<T>::node::Color Color;
    auto s = brother();
    auto p = parent();
    s->color = p->color;
    p->color = Color::BLACK;
    if (is_left_son())
    {
        right(s)->color = Color::BLACK;
        stack.pop_back();
        return rotate_left();
    }
    else
    {
        left(s)->color = Color::BLACK;
        stack.pop_back();
        return rotate_right();
    }
}

template<typename T>
auto tree<T>::helper::insert(pnode t, const_reference val) -> pnode
{
    if (t == nil)
    {
        typedef typename tree<T>::node node;
        t = pnode(new node(val, node::Color::RED, nil, nil));
        pnode p = stack.empty() ? nil : stack.back();
        if (p == nil)
        {
            stack.push_back(t);
            return t;
        }
        if (val < p->val)
            replace_stack_top_with(set_left(p, t));
        else
            replace_stack_top_with(set_right(p, t));
        stack.push_back(t);
        return t;
    }
    stack.push_back(t);
    if (val < t->val)
    {
        insert(left(t), val);
        return t;
    }
    else
    {
        insert(right(t), val);
        return t;
    }
}

// в стеке уже лежит то, что хотим удалить
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
        stack.push_back(y);
        while (left(y) != nil)
        {
            y = left(y);
            stack.push_back(y);
        }
    }
    pnode x;
    if (left(y) != nil)
        x = left(y);
    else
        x = right(y);

    auto p(parent());

    if (p == nil) // так ли?
    {
        stack.pop_back();
        stack.push_back(x);
        need_delete_fixup = true;
        return x;
    }

    if (is_left_son())
    {
        stack.pop_back();
        replace_stack_top_with(set_left(p, x));
    }
    else
    {
        stack.pop_back();
        replace_stack_top_with(set_right(p, x));
    }
    stack.push_back(x);
//    x = set_parent(x, parent(y));
//    if (parent(y) == nil)
    if (y != t)
        t->val = y->val;
    if (y->color == Color::BLACK)
    {
        need_delete_fixup = true;
    }
    return y;
}

template<typename T>
auto tree<T>::helper::erase(pnode t, const_reference val) -> pnode
{
    if (t == nil)
        return t;
    stack.push_back(t);
    if (t->val == val)
    {
        if (stack.size() == 1)
        {
            pnode new_t(new node(t->val, t->color, left(t), right(t)));
            replace_stack_top_with(new_t);
            return erase(new_t);
        }
        pnode p(parent());
        if (is_left_son())
        {
            stack.pop_back();
            pnode new_t(new node(t->val, t->color, left(t), right(t)));
            replace_stack_top_with(set_left(p, new_t));
            stack.push_back(new_t);
            return erase(new_t);
        }
        else
        {
            stack.pop_back();
            pnode new_t(new node(t->val, t->color, left(t), right(t)));
            replace_stack_top_with(set_right(p, new_t));
            stack.push_back(new_t);
            return erase(new_t);
        }
    }
    else if (val < t->val)
        return erase(left(t), val);
    else
        return erase(right(t), val);
}

template<typename T>
size_t tree<T>::helper::count(const pnode& t, const_reference val, size_t rev) const
{
    if (t == nil)
        return 0;
    if (t->val == val)
        return 1;
    else if (val < t->val)
        return count(left(t, rev), val, rev);
    else
        return count(right(t, rev), val, rev);
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
// Accept similar elements?
//    if (count(val) != 0)
//        return;
    size_++;
    insert(root, val);
    insert_case1();
    root = stack[0];
    stack.clear();
}

template<typename T>
void tree<T>::helper::erase(const_reference val)
{
    if (count(val) == 0)
        return;
    size_--;
    erase(root, val);
    if (need_delete_fixup)
    {
        delete_case1();
        need_delete_fixup = false;
    }
    root = stack[0];
    stack.clear();
}

template<typename T>
size_t tree<T>::helper::count(const_reference val) const
{
    return count(root, val, revision_);
}

template<typename T>
size_t tree<T>::helper::count(const_reference val, size_t rev) const
{
    return count(revisions.find(rev)->second.root, val, rev);
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
    return begin(revision(revision_, size_, root));
}

template<typename T>
auto tree<T>::helper::begin(size_t rev) -> iterator
{
    return begin(revisions[rev]);
}

template<typename T>
auto tree<T>::helper::begin(const revision& r) -> iterator
{
    pnode first = r.root;
    size_t revision = r.revision_;
    if (first == nil)
        return end();
    assert (stack.size() == 0);
    stack.push_back(first);
    while (left(first, revision) != nil)
    {
        first = left(first, revision);
        stack.push_back(first);
    }
    iterator it(t, first, revision, stack);
    stack.clear();
    return it;
}

template<typename T>
auto tree<T>::helper::end() -> iterator
{
    return iterator(t, nil, 0, std::vector<pnode>(0));
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
    return left(t, revision_);
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
    return right(t, revision_);
}

template<typename T>
auto tree<T>::helper::set_left(const pnode& t, const pnode& left_) -> pnode
{
    if (left(t) == left_)
        return t;
    if (t->patch == nullptr)
    {
        t->patch = ppatch(new patch(patch::What::LEFT, left_, revision_++));
        return t;
    }
    else
    {
        revision_++;
        pnode res = t->apply();
        res->left_ = left_;
        return res;
    }
}

template<typename T>
auto tree<T>::helper::set_right(const pnode& t, const pnode& right_) -> pnode
{
    if (right(t) == right_)
        return t;
    if (t->patch == nullptr)
    {
        t->patch = ppatch(new patch(patch::What::RIGHT, right_, revision_++));
        return t;
    }
    else
    {
        revision_++;
        pnode res = t->apply();
        res->right_ = right_;
        return res;
    }
}


template<typename T>
void tree<T>::helper::tag_it(size_t rev)
{
    revisions[rev] = revision(revision_, size_, root);
}

template<typename T>
void tree<T>::helper::replace_stack_top_with(const pnode& t)
{
    if (stack.back() == t)
        return;
    if (stack.size() == 1)
    {
        stack[0] = t;
        return;
    }
    if (is_left_son())
    {
        stack.pop_back();
        replace_stack_top_with(set_left(stack.back(), t));
        stack.push_back(t);
    }
    else
    {
        stack.pop_back();
        replace_stack_top_with(set_right(stack.back(), t));
        stack.push_back(t);
    }
}

template<typename T>
size_t tree<T>::helper::size() const
{
    return size_;
}

template<typename T>
size_t tree<T>::helper::size(size_t rev) const
{
    return revisions.find(rev)->second.size_;
}
