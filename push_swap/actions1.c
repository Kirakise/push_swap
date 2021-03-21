#include "header.h"

void ft_swap(t_deck **a)
{
	t_deck *tmp;
	t_deck tmp2;

	tmp2 = **a;
	**a = *tmp;
	*tmp = tmp2;
}

void ft_ss(t_deck **a, t_deck **b)
{
	ft_swap(a);
	ft_swap(b);
}

void ft_push (t_deck **a, t_deck **b)
{
	t_deck *tmp;

	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = 0;
	push_front(a, tmp);
}

void ft_rotate(t_deck **a)
{
	t_deck *tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = 0;
	push_back(a, tmp);
}

void ft_rr(t_deck **a, t_deck **b)
{
	ft_rotate(a);
	ft_rotate(b);
}
