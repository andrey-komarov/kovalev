#ifndef ERRORS_H
#define ERRORS_H

#include <iostream>
#include <string>

#ifndef RELEASE
#define DEBUG(a) std::cerr << a;
#else
#define DEBUG(a) ;
#endif

namespace geom
{
    namespace errors
    {
        struct not_implemented_yet{
            not_implemented_yet();
            not_implemented_yet(std::string);
        };
    }
}

#endif // ERRORS_H
