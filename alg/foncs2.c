/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foncs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaraway <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:59:29 by rcaraway          #+#    #+#             */
/*   Updated: 2021/05/19 14:00:48 by rcaraway         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ra(long long **a)
{
	int			i;
	long long	tmp;

	tmp = **a;
	i = 0;
	while ((*a)[i])
	{
		(*a)[i] = (*a)[i + 1];
		i++;
	}
	(*a)[i - 1] = tmp;
}

void	rr(long long **a, long long **b)
{
	ra(a);
	ra(b);
}

void	rra(long long **a)
{
	int			i;
	long long	tmp;

	i = 0;
	while ((*a)[i])
		i++;
	tmp = (*a)[i - 1];
	while (--i > 0)
		(*a)[i] = (*a)[i - 1];
	(*a)[i] = tmp;
}

void	rrr(long long **a, long long **b)
{
	rra(a);
	rra(b);
}
