#include "geom/errors.h"

namespace geom
{

namespace errors {

not_implemented_yet::not_implemented_yet() {}

not_implemented_yet::not_implemented_yet(std::string s)
{
    std::cerr << s << " is not implemented yet!" << std::endl;
}

} // errors

} // geom
