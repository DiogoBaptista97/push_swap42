/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprevrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:08:51 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/23 13:08:53 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *stack, bool truesa)
{
	int	i;
	int	j;

	if (ft_isempty(stack))
		return ;
	j = stack->stack[0];
	i = 0;
	while (i < stack->top)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[stack->top] = j;
	if (truesa)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack, bool truesb)
{
	int	i;
	int	j;

	if (ft_isempty(stack))
		return ;
	j = stack->stack[0];
	i = 0;
	while (i < stack->top)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[stack->top] = j;
	if (truesb)
		ft_printf("rra\n");
}

void	rrr(t_stack *stacka, t_stack *stackb)
{
	rra(stacka, false);
	rrb(stackb, false);
	ft_printf("rr\n");
}
