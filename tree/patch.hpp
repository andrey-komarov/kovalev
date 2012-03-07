#include "patch.h"

template<typename T>
tree<T>::patch::patch(What what, pnode new_, size_t revision) :
    what(what), new_(new_), revision(revision)
{}
