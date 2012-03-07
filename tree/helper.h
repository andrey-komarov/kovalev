#ifndef HELPER_H
#define HELPER_H

template<typename T>
struct tree<T>::helper
{
    helper(tree<T>*);
private:
    pnode nil;
    pnode root;
public:
    void insert(const_reference);
    void erase(const_reference);
    size_t count(const_reference);
    iterator begin();
    iterator end();

    void search_in(size_t rev);

    size_t depth();
    void check_rb_properties();
private:
    pnode& left(pnode&);
    pnode& right(pnode&);
    pnode& parent(pnode&);
    pnode set_left(pnode&, const pnode&);
    pnode set_right(pnode&, const pnode&);
    pnode set_parent(pnode&, const pnode&);

    pnode insert_case1(pnode);
    pnode insert_case2(pnode);
    pnode insert_case3(pnode);
    pnode insert_case4(pnode);
    pnode insert_case5(pnode);
    pnode rotate_left(pnode&);
    pnode rotate_right(pnode&);
    pnode grandparent(pnode&);
    pnode uncle(pnode& n);
    pnode brother(pnode& n);
    pnode delete_case1(pnode);
    pnode delete_case2(pnode);
    pnode delete_case3(pnode);
    pnode delete_case4(pnode);
    pnode delete_case5(pnode);
    pnode delete_case6(pnode);
    typename node::Color color(const pnode&);

    size_t depth(pnode&);
    pnode insert(pnode, const_reference, pnode& parent);
    pnode erase(pnode, const_reference);
    pnode erase(pnode);
    size_t count(pnode&, const_reference);
    void check_black_depth(pnode& t, size_t depth_need, size_t depth = 0);

    pnode fixit_insert;
    pnode fixit_delete;
    bool need_delete_fixup;
    size_t revision;
    size_t current_revision;
    tree<T>* t;
};

#include "helper.hpp"

#endif // HELPER_H
