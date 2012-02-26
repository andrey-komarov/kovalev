#include "patch.h"

template<typename T>
tree<T>::patch::patch(What what, pnode new_son, pnode p, size_t revision) :
    what(what), new_son(new_son), p(p), revision(revision)
{}
