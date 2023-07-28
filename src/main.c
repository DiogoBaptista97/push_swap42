/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:26:22 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/03/14 11:13:49 by dbraga-b         ###   ########.fr       */
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

void	handle_error(char *str, t_stack *a, t_stack *b)
{
	freestacks(a, b);
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
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

void	specific_cases(t_stack *a, t_stack *b, int argc)
{
	if (argc == 3)
		case_of_2(a);
	if (argc == 4)
		case_of_3(a);
	if (argc == 6)
		case_of_5(a, b);
}

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (-1);
	if (checkdigit(argv) == false || argv[1] == NULL)
		handle_error_1("Error\n");
	a = init_stacka(argc - 1);
	b = init_stackb(argc - 1);
	fill_stacka(&a, argv + 1);
	if (checkdouble(&a) == false)
		handle_error("Error\n", &a, &b);
	if (ft_is_sorted(&a) == true)
	{
		freestacks(&a, &b);
		return (EXIT_SUCCESS);
	}
	if (argc == 4 || argc == 3 || argc == 6)
		specific_cases(&a, &b, argc);
	else if (argc <= 100)
		insertion_sort(&a, &b);
	else
		radix_sort(&a, &b);
	freestacks(&a, &b);
	return (EXIT_SUCCESS);
}
