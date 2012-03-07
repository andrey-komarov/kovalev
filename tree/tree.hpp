#include "tree.h"

template<typename T>
tree<T>::tree() :
    root(nil<T>())
{}

template<typename T>
void tree<T>::insert(const_reference val)
{
<<<<<<< HEAD
    if (count(val) != 0)
        return;
    root = node::insert(root, val);
    if (fixit_insert<T>() != nil<T>())
    {
        insert_case1<T>(fixit_insert<T>());
        fixit_insert<T>() = nil<T>();
    }
    while (root->parent != nil<T>())
        root = root->parent;
=======
    h.insert(elem);
}

template<typename T>
void tree<T>::erase(const_reference elem)
{
    h.erase(elem);
}

template<typename T>
size_t tree<T>::count(const_reference elem)
{
    return h.count(elem);
>>>>>>> 82411e1... теперь и удаление няшное
}

template<typename T>
void tree<T>::erase(const_reference val)
{
    if (count(val) == 0)
        return;
    root = node::erase(root, val);
    if (need_delete_fixup())
    {
        delete_case1<T>(fixit_delete<T>());
        need_delete_fixup() = false;
    }
    while (root->parent != nil<T>())
        root = root->parent;
}

template<typename T>
size_t tree<T>::count(const_reference val)
{
    return node::count(root, val);
}

template<typename T>
void print(std::ostream& out, const typename tree<T>::pnode& t)
{
    if (t == nil<T>())
        return;
    print<T>(out, t->left);
    out << t->val << " ";
    print<T>(out, t->right);
    return;
}

template<typename T>
std::ostream& operator<< (std::ostream& out, const tree<T> t)
{
    print<T>(out, t.root);
    return out;
}

template<typename T>
size_t tree<T>::depth()
{
    return node::depth(root);
}

template<typename T>
void check_black_depth(const typename tree<T>::pnode& t, size_t depth_need, size_t depth = 0)
{
    if (t == nil<T>())
    {
        assert (depth_need == depth);
        return;
    }

    typedef typename tree<T>::node::Color Color;
    if (t->color == Color::RED)
    {
        assert (t->left->color == Color::BLACK);
        assert (t->left->color == Color::BLACK);
    }
    depth += t->color == Color::BLACK ? 1 : 0;
    check_black_depth<T>(t->left, depth_need, depth);
    check_black_depth<T>(t->right, depth_need, depth);
}

template<typename T>
void tree<T>::check_rb_properties() const
{
    typedef typename node::Color Color;
    assert (root->color == Color::BLACK);
    pnode now = root;
    size_t black_depth(0);
    while (now != nil<T>())
    {
        black_depth += now->color == Color::BLACK ? 1 : 0;
        now = now->left;
    }
    check_black_depth<T>(root, black_depth);
}
