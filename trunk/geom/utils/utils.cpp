#include "utils.h"

namespace geom
{

namespace utils
{

std::vector<bool> binary_repsesentation(char ch)
{
    std::vector<bool> ans(BITS_IN_BYTE, 0);
    for (size_t i = 0; i < BITS_IN_BYTE; i++)
    {
        ans[i] = (ch >> i) & 1;
    }
    return ans;
}

}

}
