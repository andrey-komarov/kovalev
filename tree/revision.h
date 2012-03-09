#ifndef REVISION_H
#define REVISION_H

template<typename T>
struct tree<T>::revision
{
    size_t revision_;
    size_t size_;
    pnode root;

    revision();
    revision(size_t revision_, size_t size_, const pnode& root);
};

#include "revision.hpp"

#endif // REVISION_H
