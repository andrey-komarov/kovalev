#include "treenode.h"

template<typename T>
tree<T>::node::node() :
    left_(nullptr), right_(nullptr), parent(nullptr),
    color(Color::BLACK),
patch(nullptr)
{

}

template<typename T>
tree<T>::node::node(const_reference val, Color color, pnode nil) :
    val(val),
    left_(nil), right_(nil), parent(nil),
    color(color),
patch(nullptr)
{}

template<typename T>
tree<T>::node::node(const_reference val, Color color, pnode left, pnode right, pnode parent) :
val(val), color(color), left_(left), right_(right), parent(parent)
{}

template<typename T>
auto tree<T>::node::apply() const -> pnode
{
    pnode res(new node(val, color, left_, right_, parent));
    if (patch->what == patch::What::LEFT)
        res->left_ = patch->new_;
    else if (patch->what == patch::What::RIGHT)
        res->right_ = patch->new_;
    else
        res->parent = patch->new_;
    return res;
}
