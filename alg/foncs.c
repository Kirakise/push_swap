#include "header.h"

void sa(long long **a)
{
    long long tmp;

    if (!(*a)[1])
        return ;
    tmp = **a;
    **a = (*a)[1];
    (*a)[1] = tmp;
}

void ss(long long **a, long long **b)
{
    sa(a);
    sa(b);
}

void pa(long long **from, long long **to)
{
    int i;
    long long tmp;

    if (!from || !**from)
        return ;
    i = 0;
    tmp = **from;
    while((*from)[i])
    {
        (*from)[i] = (*from)[i + 1];
        i++;
    }
    i = 0;
    while ((*to)[i])
        i++;
    while (i > 0)
    {
        (*to)[i] = (*to)[i - 1];
        i--;
    }
    (*to)[0] = tmp;
}
