/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:38:38 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/20 10:38:39 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdlib.h>

int	getsize(int	*stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

//fill the stack a at the begining, giving it a max top and size
void	fill_stacka(t_stack *a, char *argv[])
{
	int	size;
	int	i;

	size = a->tamanho;
	size--;
	a->top = size;
	i = 0;
	while (size >= 0)
	{
		a->stack[size] = ft_atoi(argv[i]);
		size--;
		i++;
	}
}

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
	j = a->top;
	simplify_numbers(a, array_to_sort(a));
	num = max_mum(a);
	while ((num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < a->tamanho)
	{
		ft_printf("a->stack[%d]:%d \n", i, a->stack[i]);
	}
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
	i = -1;
	while (++i < a->tamanho)
	{
		ft_printf("a->stack[%d]:%d \n", i, a->stack[i]);
	}
}

void	simplify_numbers(t_stack *a, int *sorted_array)
{
	int	i;
	int	*temp;
	int	j;

	temp = malloc (sizeof(int) * (a->tamanho));
	i = -1;
	j = a->top;
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
	i = -1;
	while (++i < a->tamanho)
	{
		ft_printf("simpli a->stack[%d]:%d \n", i, a->stack[i]);
	}
	free(temp);
	free(sorted_array);
}

/* t_stack *positive_stack(t_stack *a)
{
	t_stack	*dup;
	int		i;

	dup = malloc(sizeof(t_stack));
	dup->tamanho = a->tamanho;
	dup->top = a->top;
	dup->stack = malloc(sizeof(int) * a->tamanho);
	i = -1;
	while (++i < a->tamanho)
		dup->stack[i] = a->stack[i];
	bouble_sort(a);
	dup->stack = sorte_positivo(dup, a);
	return (dup);
} */

int	*array_to_sort(t_stack *a)
{
	int		i;
	int		*array;

	array = malloc (sizeof(int) * a->tamanho);
	i = -1;
	while (++i < a->tamanho)
		array[i] = a->stack[i];
	sort_final(array, a->tamanho);
	i = -1;
	while (++i < a->tamanho)
	{
		ft_printf("array to sorte array[%d]:%d \n", i, array[i]);
	}
	return (array);
}

void	sort_final(int	*array, int	size)
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