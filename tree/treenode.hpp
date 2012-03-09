#include "treenode.h"

template<typename T>
tree<T>::node::node() :
    left_(nullptr), right_(nullptr),
    color(Color::BLACK),
patch(nullptr)
{
    NODES++;
}

template<typename T>
tree<T>::node::node(const_reference val, Color color, pnode nil) :
    val(val),
    left_(nil), right_(nil),
    color(color),
patch(nullptr)
{}

template<typename T>
tree<T>::node::node(const_reference val, Color color, pnode left, pnode right) :
val(val), left_(left), right_(right), color(color), patch(nullptr)
{}

template<typename T>
auto tree<T>::node::apply() const -> pnode
{
    pnode res(new node(val, color, left_, right_));
    if (patch->what == patch::What::LEFT)
        res->left_ = patch->new_;
    else if (patch->what == patch::What::RIGHT)
        res->right_ = patch->new_;
    return res;
}
