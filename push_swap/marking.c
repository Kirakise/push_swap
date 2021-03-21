#include "header.h"

void markup_init(t_deck **a)
{
	t_deck *tmp;
	t_deck *tmp2;
	int count;

	tmp = *a;
	tmp2 = tmp;
	count = counttrues(tmp);
	while (tmp)
	{
		if (counttrues(tmp) > count)
		{
			count = counttrues(tmp);
			tmp2 = tmp;
		}
		tmp = tmp->next;
	}
	markup_final(a, tmp2);
}

void markup_final(t_deck **a, t_deck *ex)
{
	t_deck *tmp;
	int val;

	tmp = *a;
	val = ex->value;
	while (tmp->value != val)
	{
		tmp->keep = 0;
		tmp = tmp->next;
	}
	while (tmp)
	{
		tmp->keep = 0;
		if (tmp->value >= val)
		{
			val = tmp->value;
			tmp->keep = 1;
		}
		tmp = tmp->next;
	}
	return ;
}

int counttrues(t_deck *a)
{
	int i;
	int val;
       
	val = a->value;
	i = 1;

	while (*a)
	{
		if (a->value > val)
		{
			i++;
			val = a->value;
		}
		a = a->next;
	}
	return (i);
}
