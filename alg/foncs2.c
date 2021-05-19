#include "header.h"

void ra(long long **a)
{
    int i;
    long long tmp;

    tmp = **a;
    i = 0;
    while ((*a)[i])
    {
        (*a)[i] = (*a)[i + 1];
        i++;
    }
    (*a)[i - 1] = tmp;
}

void rr(long long **a, long long **b)
{
    ra(a);
    ra(b);
}

void rra(long long **a)
{
    int i;
    long long tmp;

    i = 0;
    while ((*a)[i])
        i++;
    tmp = (*a)[i - 1];
    while (--i > 0)
        (*a)[i] = (*a)[i - 1];
    (*a)[i] = tmp;
}

void rrr(long long **a, long long **b)
{
    rra(a);
    rra(b);
}