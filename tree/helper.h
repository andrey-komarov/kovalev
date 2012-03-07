#ifndef HELPER_H
#define HELPER_H

#include <map>
#include <utility>

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
    iterator begin(size_t rev);
    iterator end();

    void tag_it(size_t rev);

    size_t depth() const;
    void check_rb_properties() const;
private:
    pnode left(const pnode&) const;
    pnode right(const pnode&) const;
    pnode parent(const pnode&) const;
    pnode set_left(const pnode&, const pnode&);
    pnode set_right(const pnode&, const pnode&);
    pnode set_parent(const pnode&, const pnode&);
    pnode left(const pnode&, size_t revision) const;
    pnode right(const pnode&, size_t revision) const;
    pnode parent(const pnode&, size_t revision) const;


    pnode insert_case1(const pnode&);
    pnode insert_case2(const pnode&);
    pnode insert_case3(const pnode&);
    pnode insert_case4(const pnode&);
    pnode insert_case5(const pnode&);
    pnode rotate_left(const pnode&);
    pnode rotate_right(const pnode&);
    pnode grandparent(const pnode&) const;
    pnode uncle(const pnode&) const;
    pnode brother(const pnode&) const;
    pnode delete_case1(const pnode&);
    pnode delete_case2(const pnode&);
    pnode delete_case3(const pnode&);
    pnode delete_case4(const pnode&);
    pnode delete_case5(const pnode&);
    pnode delete_case6(const pnode&);
    typename node::Color color(const pnode&) const;

    size_t depth(const pnode&) const;
    pnode insert(pnode, const_reference, pnode& parent);
    pnode erase(pnode, const_reference);
    pnode erase(pnode);
    size_t count(const pnode&, const_reference) const;
    void check_black_depth(const pnode& t, size_t depth_need, size_t depth = 0) const;

    pnode fixit_insert;
    pnode fixit_delete;
    bool need_delete_fixup;
    size_t revision;
    tree<T>* t;
    std::map<size_t, std::pair<size_t, pnode> > roots;

    friend class tree<T>;
};

#include "helper.hpp"

#endif // HELPER_H
