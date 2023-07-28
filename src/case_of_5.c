/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_of_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:28:35 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/02/22 16:28:36 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdlib.h>

bool	is_in_stack(t_stack *stack, int num);

void	get_min_to_b(t_stack *a, t_stack *b, int num)
{
	if (max_int_top(a, num) == 1)
	{
		while (a->stack[a->top] != num)
			ra(a, true);
		pb(a, b);
	}
	else
	{
		while (a->stack[a->top] != num)
			rra(a, true);
		pb(a, b);
	}
}

int	get_max_to_b(t_stack *a, t_stack *b, int max, int min)
{
	int	flag;

	flag = 0;
	while (a->stack[a->top] != max)
	{
		if (a->stack[a->top] == min)
		{
			pb(a, b);
			flag = 1;
		}
		if (a->stack[a->top] == max)
			break ;
		ra(a, true);
	}
	pb(a, b);
	return (flag);
}

void	get_min_max_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int	flag;

	flag = 0;
	if (max_int_top(a, max) == 1)
		flag = get_max_to_b(a, b, max, min);
	else
	{
		while (a->stack[a->top] != max)
		{
			if (a->stack[a->top] == min)
			{
				pb(a, b);
				flag = 1;
			}
			if (a->stack[a->top] == max)
				break ;
			rra(a, true);
		}
		pb(a, b);
	}
	if (is_in_stack(a, min) == true && flag == 0)
		get_min_to_b(a, b, min);
}

bool	is_in_stack(t_stack *stack, int num)
{
	int	i;

	i = -1;
	while (++i < stack->tamanho)
	{
		if (num == stack->stack[i])
			return (true);
	}
	return (false);
}

void	case_of_5(t_stack *a, t_stack *b)
{
	int	max;
	int	min;

	simplify_numbers(a, array_to_sort(a));
	max = max_mum(a);
	min = min_num(a);
	get_min_max_to_b(a, b, min, max);
	case_of_3(a);
	max = max_mum(b);
	min = min_num(b);
	if (b->stack[b->top] == max)
	{
		pa(a, b);
		ra(a, true);
		pa(a, b);
	}
	else if (b->stack[b->top] == min)
	{
		pa(a, b);
		pa(a, b);
		ra(a, true);
	}
}
