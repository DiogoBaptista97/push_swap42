/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:41:12 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/20 12:41:14 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *stack, bool truesa)
{
	int	temp;

	if (ft_isempty(stack) || stack->top == 0)
		return ;
	temp = stack->stack[stack->top];
	stack->stack[stack->top] = stack->stack[stack->top - 1];
	stack->stack[stack->top - 1] = temp;
	if (truesa)
		ft_printf("sa\n");
}

void	sb(t_stack *stack, bool truesb)
{
	int	temp;

	if (ft_isempty(stack) || stack->top == 0)
		return ;
	temp = stack->stack[stack->top];
	stack->stack[stack->top] = stack->stack[stack->top - 1];
	stack->stack[stack->top - 1] = temp;
	if (truesb)
		ft_printf("sb\n");
}

void	ss(t_stack *stacka, t_stack*stackb)
{
	sa(stacka, false);
	sb(stackb, false);
	ft_printf("ss\n");
}
