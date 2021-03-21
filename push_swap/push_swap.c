#include "header.h"

void	push_back_init(t_deck **a, int val)
{
	int index;

	index = 0;
	if (!(*a))
	{
		*a = malloc(sizeof(struct s_deck));
		(*a)->value = val;
		(*a)->index = 0;
		return ;
	}
	while ((*a)->next)
	{
		if ((*a)->value < val)
			index++;
		(*a) = (*a)->next;
	}
	if ((*a)->value < val)
		index++;
	(*a)->next = malloc(sizeof(struct s_deck));
	*a = (*a)->next;
	(*a)->index = index;
	(*a)->value = val;
}

void	push_back(t_deck **a, t_deck *new)
{
	t_deck *tmp;

	tmp = *a;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
void	push_front(t_deck **a, t_deck *new)
{
	new->next = *a;
	*a = new;
}

int checkarg(char *s)
{
	if (s[0] == '-')
		s++;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (0);
	}
	return (1);
}

int main(int args, char **argv)
{
	t_deck *a;
	t_deck *b;
	int i;

	i = 0;
	while (i < args)
	{
		
	}
}
