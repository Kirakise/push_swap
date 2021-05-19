#include "header.h"

int sortthree2(long long **a)
{
    if (**a < 2147483648)
        **a += RAZD;
    if ((*a)[1] < 2147483648)
        (*a)[1] += RAZD;
    if ((*a)[2] < 2147483648)
        (*a)[2] += RAZD;
    while (**a > (*a)[1] || (*a)[1] > (*a)[2])
    {
        if (**a > (*a)[1] && write(1, "sa\n", 3))
            sa(a);
        if ((**a > (*a)[1] || (*a)[1] > (*a)[2]))
        {
            write(1, "rra\n", 4);
            rra(a);
        }
    }
    return (1);
}

void sortthree(long long **a)
{
    if (!(**a) || !(*a)[1])
        return ;
    if (countitems(*a) == 3 && sortthree2(a))
        return ;
    if (**a < 2147483648)
        **a += RAZD;
    if ((*a)[1] < 2147483648)
        (*a)[1] += RAZD;
    if (**a > (*a)[1] && write(1, "sa\n", 3))
        sa(a);
    if (!(*a)[2])
        return ;
    if ((*a)[2] < 2147483648)
        (*a)[2] += RAZD;
    if ((*a)[1] > (*a)[2])
    {
        write(1, "ra\nsa\nrra\n", 10);
        ra(a);
        sa(a);
        rra(a);
    }
    if ((*a)[0] > (*a)[1])
    {
        write(1, "sa\n", 3);
        sa(a);
    }
}

int countitems2(long long *a)
{
    int i;

    i = 0;
    while (a[i] && a[i] < 2147483648)
        i++;
    return (i);
}

int sortmas2(long long **a, long long **b, int sorted)
{
    int count;
    int count2;
    int max;
    int tmp;

    count = 0;
    count2 = 0;
    max = getmed(*b);
    tmp = countitems2(*b);
    while (**b && **b < 2147483648 && tmp--)
    {
        if (**b >= max && ++count && write(1, "pa\n", 3))
            pa(b, a);
        else if (write(1, "rb\n", 3) && ++count2)
            ra(b);
    }
    if (countitems(*b) != count2)
        while ((countitems(*b) > 1 && count2-- &&  write(1, "rrb\n", 4)))
            rra(b);
    if (count > 3)
        sortmas(a, b, sorted);
    else
    {
        sortthree(a);
        if (**b)
        {
            if (**b >= 2147483648)
                **b -= RAZD;
            sortmas2(a, b, countitems(*a));
        }
    }
    return (count);
}

void sortmas(long long **a, long long **b, int sorted)
{
    int i;
    int med;
    int items;
    int count;

    i = 0;
    while (countitems(*a) > sorted + 3)
    {
        items = countitems(*a);
        med = getmed(*a);
        count = 0;
        while (items-- && (*a)[i] < 2147483648)
        {
            if (**a <= med && write(1, "pb\n", 3))
                pa(a, b);
            else if (write(1, "ra\n", 3) && ++count)
                ra(a);
        }
        **b += RAZD;
        while (sorted && count-- && countitems(*a) > 1 && write(1, "rra\n", 4))
            rra(a);
    }
    if (**b)
        **b -= RAZD;
    sortthree(a);
    if (**b)
        sortmas2(a, b, countitems(*a));
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

int countargs(char **argv)
{
    int i;
    char **s;

    i = 0;
    if (isnum(argv[1]))
        while (argv[i])
            i++;
    else
    {
        s = ft_split(argv[1], ' ');
        while (s[i])
            i++;
        free(s);
    }
    return (i + 1);
}

int main(int argc, char **argv)
{
    long long *a;
    long long *b;

    if (argc == 1)
        return (0);
    a = ft_calloc(countargs(argv), sizeof(long long));
    b = ft_calloc(countargs(argv), sizeof(long long));
    parse(&a, argc, argv);
    sortmas(&a, &b, 0);
    // printmas(a);
    // write(1, "\n\n", 2);
    // printmas(b);
    free(a);
    free(b);
    return (0);
}