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

// Initializes stack a
t_stack	init_stacka(int argc)
{
	t_stack	a;

	a.tamanho = argc;
	a.stack = malloc(argc * (sizeof(int)));
	a.top = -1;
	return (a);
}

// Initializes stack b
t_stack	init_stackb(int argc)
{
	t_stack	b;

	b.tamanho = argc;
	b.stack = malloc(argc * sizeof(int));
	b.top = -1;
	return (b);
}

void	handle_error_1(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
