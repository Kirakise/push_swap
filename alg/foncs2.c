#include "header.h"

void ra(int **a)
{
    int i;
    int tmp;

    tmp = **a;
    i = 0;
    while ((*a)[i])
    {
        (*a)[i] = (*a)[i + 1];
        i++;
    }
    (*a)[i - 1] = tmp;
}

void rr(int **a, int **b)
{
    ra(a);
    ra(b);
}

void rra(int **a)
{
    int i;
    int tmp;

    i = 0;
    while ((*a)[i])
        i++;
    tmp = (*a)[i - 1];
    while (--i > 0)
        (*a)[i] = (*a)[i - 1];
    (*a)[i] = tmp;
}

void rrr(int **a, int **b)
{
    rra(a);
    rra(b);
}