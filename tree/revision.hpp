#include "revision.h"

template<typename T>
tree<T>::revision::revision()
{}

template<typename T>
tree<T>::revision::revision(size_t revision_, size_t size_, const pnode& root) :
revision_(revision_), size_(size_), root(root)
{}
