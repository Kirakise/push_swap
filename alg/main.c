#include "header.h"

int *getsortmas(int *a, int count)
{
    int *ret;
    int i;
    int j;
    int tmp;

    ret = ft_calloc(count, sizeof(int));
    ft_memmove(ret, a, count);
    i = 0;
    while (ret[i])
    {
        j = i + 1;
        while (ret[j])
        {
            if (ret[i] > ret[j])
            {
                tmp = ret[i];
                ret[i] = ret[j];
                ret[j] = tmp;
            }
            j++;
        }
        i++;
    }
    return (ret);
}

int ft_abs(int a)
{
    if (a > 0)
        return (a);
    else
        return (-a);
}

int checkcluster(int *a, int *sorted, int i, int j)
{
    int i1;
    int first;
    int last;

    i1 = 0;
    first = -1;
    while(a[i1])
    {
        if (a[i1] >= sorted[i] && a[i1] <= sorted[j])
        {
            first = i1;
            break;
        }
        i++;
    }
    i1 = countitems(a);
    while (--i1 && a[i1])
    {
        if (a[i1] >= sorted[i] && a[i1] <= sorted[j])
        {
            last = i1;
            break;
        }
    }
    if (first == -1 || ft_abs(countitems(a)/2 - first) < ft_abs(countitems(a)/2 - last))
        return (first);
    return (last);
}

void pushtob(int **a, int **b)
{
    int i;
    int tmp;
    int res;
    
    i = 0;
    tmp = 100000000;
    res = 0;
    while (*b[i])
    {
        if (ft_abs((*b)[i] - **a) < tmp)
        {
            tmp = ft_abs((*b)[i] - **a);
            res = i;
        }
        i++;
    }
    if (countitems(*b) / 2 - res > 0)
        while (res--)
            ra(b);
    else
        while (res++ < countitems(*b))
            rra(b);
    pa(a, b);
}

void sortmas(int **a, int **b, int *sorted, int clusters)
{
        int tmp;
        int count;
        int i;

        count = countitems(*a) /clusters;
        i = -1;
        while (++i < clusters)
        {
            while(checkcluster(*a, sorted, 0 + count * i, count * i - 1) != -1)
            {
                tmp = checkcluster(*a, sorted, 0 + count * i, count * i - 1) != -1;
                if (countitems(*a) / 2 - tmp > 0)
                    while (tmp--)
                        ra(a);
                else
                    while (tmp++ < countitems(*a))
                        rra(a);
                pushtob(a, b);
            }
        }
        while (**b)
            pa(b, a);
}

int checkinput(char **s)
{
    int i;
    int j;
    
    i = 1;
    while (s[i])
    {
        j = 0;
        while (s[i][j])
        {
            if (s[i][j] >= '0' && s[i][j] <= '9')
                j++;
            else
                return (1);
        }
        i++;
    }
    return (0);
}

int checknums(int *a, int zeroflag)
{
    int i;
    int j;

    i = 0;
    while (a[i])
    {
        j = i + 1;
        while (a[j])
        {
            if (a[i] == 1 && a[j] == 1 && zeroflag)
            {
                zeroflag = 0;
                j++;
            }
            else if (a[i] == a[j])
                return (1);
            else
                j++;
        }
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int *a;
    int *b;
    int i;
    int zeroflag;

    a = ft_calloc(argc, sizeof(int));
    b = ft_calloc(argc, sizeof(int));
    i = 0;
    while (++i < argc)
    {
        a[i - 1] = ft_atoi(argv[i]);
        if (a[i - 1] == 0)
        {
            zeroflag = 1;
            a[i - 1] = 1;
        }
    }
    if (checkinput(argv) || checknums(a, zeroflag))
    {
        printf("Error\n");
        exit(0);
    }
    if (argc - 1 <= 100)
        sortmas(&a, &b, getsortmas(a, argc), 5);
    else
        sortmas(&a, &b, getsortmas(a, argc), 11);
    printmas(a);
    free(a);
    free(b);
}