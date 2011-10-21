#include "predicates.h"

int predicates::orientation(const point &a, const point &b, const point &c)
{
    return utils::signum((b - a) * (c - a));
}
