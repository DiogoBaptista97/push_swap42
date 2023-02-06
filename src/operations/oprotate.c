/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oprotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:08:45 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/23 13:08:46 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack *stack, bool truesa)
{
	int	i;
	int	j;

	if (ft_isempty(stack))
		return ;
	j = stack->stack[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[0] = j;
	if (truesa)
		ft_printf("ra\n");
}

void	rb(t_stack *stack, bool truesb)
{
	int	i;
	int	j;

	if (ft_isempty(stack))
		return ;
	j = stack->stack[stack->top];
	i = stack->top;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[0] = j;
	if (truesb)
		ft_printf("rb\n");
}

void	rr(t_stack *stacka, t_stack *stackb)
{
	ra(stacka, false);
	rb(stackb, false);
	ft_printf("rr\n");
}
