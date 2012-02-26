#ifndef HELPER_H
#define HELPER_H

template<typename T>
struct tree<T>::helper
{
    helper();

    pnode insert_case1(pnode);
    pnode insert_case2(size_t revision);
    pnode insert_case3(pnode);
    pnode insert_case4(pnode);
    pnode insert_case5(pnode);
    pnode rotate_left(pnode&);
    pnode rotate_right(pnode&);
    pnode grandparent(const pnode&);
    pnode uncle(const pnode& n);
    pnode brother(const pnode& n);
    pnode delete_case1(pnode);
    pnode delete_case2(pnode);
    pnode delete_case3(pnode);
    pnode delete_case4(pnode);
    pnode delete_case5(pnode);
    pnode delete_case6(pnode);
    node::Color color(const pnode&);

    size_t depth(pnode&);
    pnode insert(pnode, const_reference, const pnode& parent = nil<T>());
    pnode erase(pnode, const_reference);
    pnode erase(pnode);
    size_t count(pnode&, const_reference);

    pnode nil;
    pnode root;

    pnode fixit_insert;
    pnode fixit_delete;
    bool need_delete_fixup;
    size_t revision;
};

#include "helper.hpp"

#endif // HELPER_H
