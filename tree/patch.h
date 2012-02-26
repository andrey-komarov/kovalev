#ifndef PATCH_H
#define PATCH_H

template<typename T>
struct tree<T>::patch
{
    enum What
    {
        LEFT, RIGHT
    };

    typedef typename tree<T>::pnode pnode;

    What what;
    pnode new_son;
    pnode p;
    size_t revision;

    patch(What what, pnode new_son, pnode p, size_t revision);
};

#include "patch.hpp"

#endif // PATCH_H
