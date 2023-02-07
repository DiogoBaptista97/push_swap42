/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:22 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/20 14:26:23 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	freestacks(t_stack *stacka, t_stack *stackb)
{
	free(stacka->stack);
	free(stackb->stack);
}

//print to visualize the stacks
void	printstacks(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	t;

	i = a->top;
	j = b->top;
	t = a->tamanho;
	while (t >= 0)
	{
		if (i >= 0)
			ft_printf("%d", a->stack[i--]);
		ft_printf(" ");
		if (j >= 0)
			ft_printf("%d", b->stack[j--]);
		if (i >= 0 || j >= 0)
			ft_printf("\n");
		t--;
	}
	ft_printf("\n");
	ft_printf("a");
	ft_printf(" ");
	ft_printf("b\n");
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
	{
		ft_printf("nao tem argumentos");
		exit(EXIT_FAILURE);
	}
	if (checkdigit(argv) == false)
	{
		ft_printf("nao sao todos digits");
		exit(EXIT_FAILURE);
	}
	a = init_stacka(argc - 1);
	b = init_stackb(argc - 1);
	fill_stacka(&a, argv + 1);
//	printstacks(&a, &b);
	radix_sort(&a, &b);
//	printstacks(&a, &b);
	freestacks(&a, &b);
	return (EXIT_SUCCESS);
}
