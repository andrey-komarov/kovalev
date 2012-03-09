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
    pnode set_left(const pnode&, const pnode&);
    pnode set_right(const pnode&, const pnode&);
    pnode left(const pnode&, size_t revision) const;
    pnode right(const pnode&, size_t revision) const;
    void replace_stack_top_with(const pnode&);

    iterator begin(const revision&);

    pnode insert_case1();
    pnode insert_case2();
    pnode insert_case3();
    pnode insert_case4();
    pnode insert_case5();
    pnode rotate_left();
    pnode rotate_right();
    pnode grandparent() const;
    pnode parent() const;
    pnode uncle() const;
    pnode brother() const;
    bool is_left_son() const;
    bool is_right_son() const;
    pnode delete_case1();
    pnode delete_case2();
    pnode delete_case3();
    pnode delete_case4();
    pnode delete_case5();
    pnode delete_case6();
    typename node::Color color(const pnode&) const;

    size_t depth(const pnode&) const;
    pnode insert(pnode, const_reference);
    pnode erase(pnode, const_reference);
    pnode erase(pnode);
    size_t count(const pnode&, const_reference) const;
    void check_black_depth(const pnode& t, size_t depth_need, size_t depth = 0) const;

    size_t revision_;
    size_t size_;
    tree<T>* t;
    std::map<size_t, revision> revisions;
    bool need_delete_fixup;
    std::vector<pnode> stack;

    friend class tree<T>;
};

#include "helper.hpp"

#endif // HELPER_H
