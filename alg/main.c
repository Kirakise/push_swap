#include "header.h"

void sortmas2(int **a, int **b)
{
    int count;
    int max;

    while (**b)
    {
        max = getmax(*b);
        while (**b != max && write(1, "rb\n", 3))
        {
            ra(b);
            count++;
        }
        write(1, "pa\n", 3);
        pa(b, a);
        while (count-- && write(1, "rrb\n", 4))
            rra(b);
        count = 0;
    }
}

void sortmas(int **a, int **b)
{
    int i;
    int med;
    int items;

    i = 0;
    while (countitems(*a) > 2)
    {
        items = countitems(*a);
        med = getmed(*a);
        while (items--)
        {
            if (**a < med && write(1, "pb\n", 3))
                pa(a, b);
            else if (write(1, "ra\n", 3))
                ra(a);
        }
    }
    if (countitems(*a) == 2 && **a > (*a)[1] && write(1, "sa\n", 3))
        sa(a);
    sortmas2(a, b);
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
    sortmas(&a, &b);
    //printmas(a);
    free(a);
    free(b);
}