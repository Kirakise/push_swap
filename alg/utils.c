#include "header.h"

int		ft_atoi(const char *str)
{
	int			plus;
	long long	num;
	long long	num2;

	plus = 0;
	num = 0;
	num2 = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f'
			|| *str == '\r' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			plus = plus == 0 ? 1 : 0;
	while (*str >= '0' && *str <= '9')
	{
		if (plus == 0 && num2 < num)
			return (-1);
		if (plus == 1 && num2 > num)
			return (0);
		num2 = num;
		num = plus == 0 ? num * 10 - *str + 48 : num * 10 + *str - 48;
		str++;
	}
	return (-num);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*tmp;
	int		temp;

	temp = size * count;
	p = malloc(count * size);
	if (p == 0)
		return (0);
	tmp = p;
	while (temp--)
		*tmp++ = 0;
	return (p);
}

int checkifsorted(int **a)
{
    int i;

    i = 0;
    while ((*a)[i])
    {
        if ((*a)[i + 1] > (*a)[i] || !(*a)[i + 1])
            i++;
        else
            return (0);
    }
    return (1);
}