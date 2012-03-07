#ifndef PATCH_H
#define PATCH_H

template<typename T>
struct tree<T>::patch
{
    enum class What
    {
        LEFT, RIGHT, PARENT
    };

    typedef typename tree<T>::pnode pnode;

    What what;
    pnode new_;
    size_t revision;

    patch(What what, pnode new_, size_t revision);
};

#include "patch.hpp"

#endif // PATCH_H
