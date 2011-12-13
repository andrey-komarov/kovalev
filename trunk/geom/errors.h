#ifndef ERRORS_H
#define ERRORS_H

#ifndef RELEASE
#include <iostream>
#define DEBUG(a) std::cerr << a;
#endif

namespace geom
{
    namespace errors
    {
        class not_implemented_yet{};
    }
}

#endif // ERRORS_H
