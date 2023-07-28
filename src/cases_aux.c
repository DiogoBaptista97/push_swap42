/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_new_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:02:56 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/02/06 12:02:57 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdlib.h>

int	min_num(t_stack *a)
{
	int	i;
	int	min;

	i = -1;
	min = a->stack[0];
	while (++i < a->tamanho)
	{
		if (min > a->stack[i])
			min = a->stack[i];
	}
	return (min);
}

int	min_int_top(t_stack *b, int min)
{
	int	i;

	i = b->top;
	while (i > (b->top / 2))
	{
		if (b->stack[i] == min)
			return (1);
		i--;
	}
	return (0);
}

int	max_int_top(t_stack *b, int max)
{
	int	i;

	i = b->top;
	while (i > (b->top / 2))
	{
		if (b->stack[i] == max)
			return (1);
		i--;
	}
	return (0);
}

void	push_small_to_b(t_stack *a, t_stack *b, int mid_point)
{
	while (a->stack[a->top] < mid_point)
		pb(a, b);
}

void	push_small_to_b_bottom(t_stack *a, t_stack *b, int mid_point)
{
	while (a->stack[0] < mid_point)
	{
		rra(a, true);
		pb(a, b);
	}
}
