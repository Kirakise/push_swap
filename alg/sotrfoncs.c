#include "header.h"

void swap(long long **a, int i, int j)
{
    int tmp;

    tmp = (*a)[i];
    (*a)[i] = (*a)[j];
    (*a)[j] = tmp;
}

int getmed(long long *a)
{
    int i;
    long long *tmp2;
    int tmp3;
    
    i = 0;
    tmp2 = ft_calloc(countitems(a) + 1, sizeof(long long));
    while (a[i] && a[i] <= 2147483647)
    {
        tmp2[i] = a[i];   
        i++;
    }
    i = 0;
    while (tmp2[i])
    {
        tmp3 = i + 1;
        while (tmp2[tmp3])
        {
            if (tmp2[tmp3] < tmp2[i])
                swap(&tmp2, tmp3, i);
            tmp3++;
        }
        i++;
    }
    tmp3 = tmp2[i / 2];
    free(tmp2);
    return (tmp3);
}

int getmax(long long *a)
{
    int i;
    int ret;
    int flag;

    i = 0;
    flag = 0;
    ret = -200000000;
    while (a[i])
    {
        if (a[i] > 2147483647)
        {
            flag = 1;
            a[i] -= RAZD;
        }
        if (a[i] > ret)
            ret = a[i];
        if (flag)
        {
            flag = 0;
            a[i] += RAZD;
        }
        i++;
    }
    return (ret);
}

int countitems(long long *a)
{
    int i;
    
    i = 0;
    while (a[i])
        i++;
    return (i);
}

void printmas(long long *a)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (a[i])
    {
        if (a[i] > 2147483647)
            a[i] -= RAZD;
        if (a[i] == 1 && a[i + 1] == 1)
            a[i] = 0;
        printf("%lli\n", a[i++]);
    }
}