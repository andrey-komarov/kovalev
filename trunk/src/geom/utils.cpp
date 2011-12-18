#include "utils.h"

std::vector<bool> binary_repsesentation(char ch)
{
    std::vector<bool> ans(geom::utils::BITS_IN_BYTE, 0);
    for (size_t i = 0; i < geom::utils::BITS_IN_BYTE; i++)
    {
        ans[i] = (ch >> i) & 1;
    }
    return ans;
}
