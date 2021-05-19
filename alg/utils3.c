#include "header.h"

int	sortthree2(long long **a)
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

void	sortthree(long long **a)
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
	if ((*a)[0] > (*a)[1] && write(1, "sa\n", 3))
		sa(a);
}

int	countitems2(long long *a)
{
	int	i;

	i = 0;
	while (a[i] && a[i] < 2147483648)
		i++;
	return (i);
}

int	countargs(char **argv)
{
	int		i;
	char	**s;

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
