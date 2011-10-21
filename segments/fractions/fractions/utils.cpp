#include "utils.h"

std::vector<bool> utils::binary_repsesentation(char ch)
{
    std::vector<bool> ans(BITS_IN_BYTE, 0);
    for (size_t i = 0; i < BITS_IN_BYTE; i++)
    {
        ans[i] = (ch >> i) & 1;
    }
    return ans;
}

fraction utils::make_fraction(double a)
{
    static const size_t MANTISS = 52;
    static const size_t EXPONENT = 11;
    std::vector<bool> repr = utils::binary_repsesentation(a);
    int sign = repr[MANTISS + EXPONENT] ? -1 : 1;
    big_int mantiss = 1;
    for (size_t i = 0; i < MANTISS; i++)
    {
        mantiss *= 2;
        mantiss += repr[MANTISS - i - 1] ? 1 : 0;
    }
    int exponent = 0;
    for (size_t i = 0; i < EXPONENT; i++)
    {
        exponent *= 2;
        exponent += repr[MANTISS + EXPONENT - i - 1] ? 1 : 0;
    }
    exponent = exponent - ((1 << (EXPONENT - 1)) - 1) - MANTISS;
    big_int q = 1;
    for (size_t i = 0; i < abs(exponent); i++)
    {
        q *= 2; // Optimizable
    }
    if (exponent >= 0)
        return fraction(sign * mantiss * q, 1);
    else
        return fraction(sign * mantiss, q);
}
