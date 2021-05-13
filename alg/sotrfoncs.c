#include "header.h"

void swap(int **a, int i, int j)
{
    int tmp;

    tmp = (*a)[i];
    (*a)[i] = (*a)[j];
    (*a)[j] = tmp;
}

int getmed(int *a)
{
    int i;
    int *tmp2;
    int tmp3;
    
    i = 0;
    tmp2 = ft_calloc(countitems(a) + 1, sizeof(int));
    while (a[i])
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

int getmax(int *a, int regime)
{
    int i;
    int ret;

    i = 0;
    if (regime == 1)
        ret = -200000000;
    else if (regime == -1)
        ret = 200000000;
    while (a[i])
    {
        if (regime == 1 && a[i] > ret)
            ret = a[i];
        else if (regime == -1 && a[i] < ret)
            ret = a[i];
        i++;
    }
    return (ret);
}

int countitems(int *a)
{
    int i;
    
    i = 0;
    while (a[i])
        i++;
    return (i);
}

void printmas(int *a)
{
    int i;

    i = 0;
    while (a[i])
        printf("%i\n", a[i++]);
}