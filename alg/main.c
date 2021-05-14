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
        items = countitems(*a) - 1;
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
    int *a;
    int *b;

    a = ft_calloc(countargs(argv), sizeof(int));
    b = ft_calloc(countargs(argv), sizeof(int));
    parse(&a, argc, argv);
    sortmas(&a, &b);
    //printmas(a);
    free(a);
    free(b);
}