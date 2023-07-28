/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rodix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:24:10 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/02/22 16:24:11 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdlib.h>

int	max_mum(t_stack *a)
{
	int	i;
	int	nub;

	nub = a->stack[0];
	i = -1;
	while (++i <= a->tamanho)
	{
		if (a->stack[i] > nub)
			nub = a->stack[i];
	}
	return (nub);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	num;
	int	i;
	int	j;

	max_bits = 0;
	simplify_numbers(a, array_to_sort(a));
	num = max_mum(a);
	while ((num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while ((!ft_is_sorted(a)) && ++j < a->tamanho)
		{
			num = a->stack[a->top];
			if (((num >> i) & 1) == 1)
				ra(a, true);
			else
				pb(a, b);
		}
		while (!ft_isempty(b))
			pa(a, b);
	}
}

void	simplify_numbers(t_stack *a, int *sorted_array)
{
	int	i;
	int	*temp;
	int	j;

	temp = malloc (sizeof(int) * (a->tamanho));
	i = -1;
	while (++i < a->tamanho)
	{
		j = -1;
		while (++j < a->tamanho)
		{
			if (sorted_array[i] == a->stack[j])
				temp[j] = i;
		}
	}
	i = -1;
	while (++i < a->tamanho)
		a->stack[i] = temp[i];
	free(temp);
	free(sorted_array);
}

int	*array_to_sort(t_stack *a)
{
	int		i;
	int		*array;

	array = malloc (sizeof(int) * a->tamanho);
	i = -1;
	while (++i < a->tamanho)
		array[i] = a->stack[i];
	sort_final(array, a->tamanho);
	return (array);
}

void	sort_final(int	*array, int size)
{
	int	i;
	int	j;
	int	num;

	i = 1;
	while (i < size)
	{
		num = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > num)
		{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = num;
		i++;
	}
}
