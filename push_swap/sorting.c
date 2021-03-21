#include "header.h"

int checkfalse(t_deck **a)
{
	t_deck *tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->keep = 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int needsa(t_deck **a)
{
	int a;
	int b;
	t_deck *tmp;

	tmp = *a;
	a = 0;
	b = 0;
	while (tmp)
	{
		if (tmp->keep)
			a++;
		tmp = tmp->next;
	}
	ft_swap(a);
	tmp = *a;
	while (tmp)
	{
		if (tmp->keep)
			b++;
		tmp = tmp->next;
	}
	if (a >= b) {
		ft_swap(a);
		return (1);
	}
	return (0);
}

void sort(t_deck **a, t_deck **b)
{
	while (checkfalse(a))
	{
		if (!needsa(a))
			a += 0;
		else if ((*a)->keep == 0)
			ft_push(b, a);
		else
			ft_rotate(a);
	}
}
