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
	simplify_numbers(a, bouble_sort(a));
	num = max_mum(a);
	while ((num >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while ((ft_is_sorted(a) != 1) && ++j < a->tamanho)
		{
			num = a->stack[a->top];
			if (((num >> i) & 0b00000001) == 1)
				ra(a, false);
			else
				pb(a, b);
		}
		while (ft_isempty(b))
			pa(a, b);
	}
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

int	*bouble_sort(t_stack *a)
{
	int		i;
	int		j;
	int		temp;

	i = 0;
	while (++i < a->tamanho)
	{
		temp = a->stack[i];
		j = i - 1;
		while (j >= 0 && a->stack[j] > temp)
		{
			a->stack[j + 1] = a->stack[j];
			j--;
		}
		a->stack[j + 1] = temp;
	}
	return (a->stack);
}

/* int	*sorte_positivo(t_stack *dup, t_stack *a)
{
	int	i;
	int	*stack;

	stack = malloc(sizeof(int) * dup->tamanho);
	if (!stack)
		return (NULL);
	i = -1;
	while (++i < a->tamanho)
	{
		ft_printf("round 2 pos no a int %d: %d \n", i, a->stack[i]);
	}
	i = -1;
	while (++i < a->tamanho)
	{
		ft_printf("pos no dup int %d: %d \n", i, dup->stack[i]);
	}
	i = -1;

	i = -1;
	while (++i < a->tamanho)
	{
		ft_printf("o digito na pos %d: %d \n", i, stack[i]);
	}
	return (stack);
} */

void	simplify_numbers(t_stack *a, int *sorted_array)
{
	int	i;
	int	*temp;
	int	j;

	i = -1;
	temp = malloc(a->tamanho * sizeof(int));
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
/*	i = -1;
 	while (++i < a->tamanho)
	{
		ft_printf("o digito na pos %d: %d \n", i, a->stack[i]);
	} */
	free(temp);
}
