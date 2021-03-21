#include "header.h"

void ft_revrot(t_deck **a)
{
	t_deck *tmp;
	t_deck *tmp2;

	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = 0;
	push_front(a, tmp2);
}

void ft_rrr(t_deck **a, t_deck **b)
{
	ft_revrot(a);
	ft_revrot(b);
}
