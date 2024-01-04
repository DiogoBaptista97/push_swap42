/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_of_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:30:41 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/02/15 13:30:42 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdlib.h>

int	*get_array(t_stack *a);

void	case_of_3(t_stack *a)
{
	if (a->stack[0] > a->stack[1] && a->stack[0] > a->stack[2]
		&& a->stack[1] < a->stack[2])
		sa(a, true);
	else if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2]
		&& a->stack[1] < a->stack[2])
	{
		sa(a, true);
		rra(a, true);
	}
	else if (a->stack[0] > a->stack[1] && a->stack[0] < a->stack[2]
		&& a->stack[1] < a->stack[2])
		ra(a, true);
	else if (a->stack[0] < a->stack[1] && a->stack[0] > a->stack[2]
		&& a->stack[1] > a->stack[2])
	{
		sa(a, true);
		ra(a, true);
	}
	else if (a->stack[0] < a->stack[1] && a->stack[0] < a->stack[2]
		&& a->stack[1] > a->stack[2])
		rra(a, true);
}

int	get_mid_point(t_stack *a, int start)
{
	int	mid_point;
	int	*array;
	int	chunk_size;
	int	i;

	mid_point = 0;
	chunk_size = ((a->top + 1) - start);
	array = malloc(sizeof(int) * a->tamanho);
	i = -1;
	while ((++i + start) < (a->top + 1))
		array[i] = a->stack[i + start];
	sort_final(array, chunk_size);
	i = -1;
	mid_point = array[(chunk_size / 2)];
	free (array);
	array = NULL;
	return (mid_point);
}

void	move_to_a(t_stack *a, t_stack *b, int max)
{
	if (max_int_top(b, max) == 1)
	{
		while (b->stack[b->top] < max)
			rb(b, true);
		pa(a, b);
	}
	else
	{
		while (b->stack[b->top] < max)
			rrb(b, true);
		pa(a, b);
	}
}

int	max_point(t_stack *b)
{
	int	i;
	int	max;

	i = -1;
	max = b->stack[0];
	while (++i < b->top)
	{
		if (max < b->stack[i])
			max = b->stack[i];
	}
	return (max);
}

void	insertion_sort(t_stack *a, t_stack *b)
{
	int	mid_point;
	int	chunks;

	chunks = 1;
	simplify_numbers(a, array_to_sort(a));
	while (a->top > 1)
	{
		mid_point = get_mid_point(a, 0);
		push_small_to_b(a, b, mid_point);
		push_small_to_b_bottom(a, b, mid_point);
		final_movement(a, b, mid_point, chunks++);
	}
	if (a->stack[a->top] > a->stack[a->top - 1])
		sa(a, true);
	while (b->top != -1)
		move_to_a(a, b, max_point(b));
}
/* 
	2 1 3 sa
	3 2 1 sa rra
	3 1 2 ra
	1 3 2 sa
	2 3 1 rra
 */
