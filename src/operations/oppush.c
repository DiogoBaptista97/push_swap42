/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oppush.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:08:37 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/23 13:08:38 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_stack *stacka, t_stack *stackb)
{
	if (ft_isempty(stacka) || ft_isfull(stackb)
		|| stacka->top == -1 || stackb->top == stackb->tamanho)
		return ;
	stackb->top++;
	stackb->stack[stackb->top] = stacka->stack[stacka->top];
	stacka->top--;
	ft_printf("pb\n");
}

void	pa(t_stack *stacka, t_stack *stackb)
{
	if (ft_isempty(stackb) || ft_isfull(stacka)
		|| stackb->top == -1 || stacka->top == stacka->tamanho)
		return ;
	stacka->top++;
	stacka->stack[stacka->top] = stackb->stack[stackb->top];
	stackb->top--;
	ft_printf("pa\n");
}
