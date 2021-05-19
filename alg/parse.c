#include "header.h"

void	parsestr(long long **a, char *argv, int *zeroflag)
{
	char	**s;
	int		i;

	s = ft_split(argv, ' ');
	i = 0;
	*zeroflag = 0;
	while (s[i])
	{
		if (isnum(s[i]))
		{
			(*a)[i] = ft_atoi(s[i]);
			if ((*a)[i] == 0)
			{
				(*a)[i] = 1;
				*zeroflag = 1;
			}
		}
		else
		{
			write(1, "Error\n", 7);
			exit(-1);
		}
		i++;
	}
}

void	parsearr(long long **a, char **argv, int argc, int *zeroflag)
{
	int	i;

	*zeroflag = 0;
	i = 0;
	while (++i < argc)
	{
		if (!isnum(argv[i]))
		{
			write(1, "Error\n", 7);
			exit(-1);
		}
		(*a)[i - 1] = ft_atoi(argv[i]);
		if ((*a)[i - 1] == 0)
		{
			*zeroflag = 1;
			(*a)[i - 1] = 1;
		}
	}
}

int	issorted(long long **a)
{
	int	i;

	i = 1;
	while ((*a)[i])
	{
		if ((*a)[i] < (*a)[i - 1])
			return (0);
		i++;
	}
	return (1);
}

void	parse(long long **a, int argc, char **argv)
{
	int	i;
	int	zeroflag;

	i = 0;
	if (argc == 1)
		exit(0);
	if (!isnum(argv[1]))
	{
		parsestr(a, argv[1], &zeroflag);
		return ;
	}
	else
		parsearr(a, argv, argc, &zeroflag);
	if (checknums(*a, zeroflag))
	{
		printf("Error\n");
		exit(-1);
	}
	if (issorted(a))
		exit(0);
}
