#ifndef HELPER_H
#define HELPER_H

#include <map>
#include <utility>
#include <vector>

template<typename T>
struct tree<T>::helper
{
    helper(tree<T>*);
private:
    pnode root;
public:
    void insert(const_reference);
    void erase(const_reference);

    size_t size() const;
    size_t size(size_t rev) const;

    size_t count(const_reference) const;
    size_t count(const_reference, size_t rev) const;

    iterator lower_bound(const_reference) const;
    iterator lower_bound(const_reference, size_t revision) const;

    iterator begin() const;
    iterator begin(size_t rev) const;
    iterator end() const;

    void tag_it(size_t rev);

    size_t depth() const;
    void check_rb_properties() const;
private:
    pnode left(const pnode&) const;
    pnode right(const pnode&) const;
    pnode set_left(const pnode&, const pnode&);
    pnode set_right(const pnode&, const pnode&);
    pnode left(const pnode&, size_t revision) const;
    pnode right(const pnode&, size_t revision) const;
    void replace_stack_top_with(const pnode&);

    iterator begin(const revision&) const;
    iterator lower_bound(const pnode&, const_reference val, size_t revision) const;
    void lower_bound_(const pnode&, const_reference val, size_t revision) const;

    void insert_case1();
    void insert_case2();
    void insert_case3();
    void insert_case4();
    void insert_case5();
    void rotate_left();
    void rotate_right();
    pnode grandparent() const;
    pnode parent() const;
    pnode uncle() const;
    pnode brother() const;
    bool is_left_son() const;
    bool is_right_son() const;
    void delete_case1();
    void delete_case2();
    void delete_case3();
    void delete_case4();
    void delete_case5();
    void delete_case6();
    typename node::Color color(const pnode&) const;

    size_t depth(const pnode&) const;
    void insert(pnode, const_reference);
    void erase(pnode, const_reference);
    void erase(pnode);
    size_t count(const pnode&, const_reference, size_t rev) const;
    void check_black_depth(const pnode& t, size_t depth_need, size_t depth = 0) const;

    size_t revision_;
    size_t size_;
    tree<T>* t;
    std::map<size_t, revision> revisions;
    bool need_delete_fixup;
    mutable std::vector<pnode> stack;

    friend class tree<T>;
};

#include "helper.hpp"

#endif // HELPER_H
