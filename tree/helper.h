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
    size_t count(const_reference) const;
    iterator begin();
    iterator end();

    size_t depth() const;
    void check_rb_properties() const;
private:
    pnode& left(pnode&);
    pnode& right(pnode&);
    pnode& parent(pnode&);
    pnode& set_left(pnode&, pnode&);
    pnode& set_right(pnode&, pnode&);
    pnode& set_parent(pnode&, pnode&);

    pnode insert_case1(pnode);
    pnode insert_case2(pnode);
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
    typename node::Color color(const pnode&);

    size_t depth(const pnode&) const;
    pnode insert(pnode, const_reference, const pnode& parent);
    pnode erase(pnode, const_reference);
    pnode erase(pnode);
    size_t count(const pnode&, const_reference) const;
    void check_black_depth(const pnode& t, size_t depth_need, size_t depth = 0) const;

    tree<T>* t;
    pnode fixit_insert;
    pnode fixit_delete;
    bool need_delete_fixup;
    size_t revision;
    size_t current_revision;
};

#include "helper.hpp"

#endif // HELPER_H
