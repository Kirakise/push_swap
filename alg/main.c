#include "header.h"

int *getsortmas(int *a, int count)
{
    int *ret;
    int i;
    int j;
    int tmp;

    ret = ft_calloc(count, sizeof(int));
    ft_memmove(ret, a, count * sizeof(int));
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

    i1 = -1;
    first = -1;
    while(a[++i1])
    {
        if (a[i1] >= sorted[i] && a[i1] <= sorted[j])
        {
            first = i1;
            break;
        }
    }
    i1 = countitems(a);
    while (a[--i1])
    {
        if (a[i1] >= sorted[i] && a[i1] <= sorted[j])
        {
            last = i1;
            break;
        }
    }
    if (first == -1 || ft_abs(countitems(a)/2 - first) <= ft_abs(countitems(a)/2 - last))
        return (first);
    return (last);
}

void pushtob(int **a, int **b)
{
    int i;
    
    i = 0;
    if (**a == getmax(*b, 1))
    {
        while ((*b)[i] != getmax(*b, -1))
            i++;
        if (countitems(*b) / 2 - i > 0)
            while (i-- && write(1, "rb\n", 3))
                ra(b);
            else while (i++ < countitems(*b) && write(1, "rrb\n", 4))
                rra(b);
    }
    else if (**a == getmax(*b, -1))
    {
        while ((*b)[i] != getmax(*b, 1))
            i++;
        if (countitems(*b) / 2 - i > 0)
            while (i-- && write(1, "rb\n", 3))
                ra(b);
            else while (i++ < countitems(*b) && write(1, "rrb\n", 4))
                rra(b);
    }
    write(1, "pb\n", 3);
    pa(a, b);
}

void correct(int **b)
{
    int i;
    int tmp;

    tmp = getmax(*b, 1);
    i = 0;
    while ((*b)[i] != tmp)
        i++;
    if (countitems(*b) / 2 - i > 0)
        while(i++ < countitems(*b) && write(1, "rrb\n", 4))
            rra(b);
    else
        while(i-- && write(1, "rb\n", 4))
            ra(b);
}
void foo()
{}

void sortmas(int **a, int **b, int *sorted, int clusters)
{
        int tmp;
        int count;
        int i;

        count = countitems(*a) /clusters;
        i = -1;
        while (++i < clusters)
        {
            while(checkcluster(*a, sorted, count * i, count * (i + 1) - 1) != -1)
            {
                tmp = checkcluster(*a, sorted, count * i, count * (i + 1) - 1);
                if (countitems(*a) / 2 - tmp > 0)
                    while (tmp-- && write(1, "ra\n", 3))
                        ra(a);
                else
                    while (tmp++ < countitems(*a) && write(1, "rra\n", 4))
                        rra(a);
                pushtob(a, b);
            }
        }
        foo();
        while (**b)
        {
            correct(b);
            write(1, "pa\n", 3);
            pa(b, a);
        }
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
    //printmas(a);
    free(a);
    free(b);
}