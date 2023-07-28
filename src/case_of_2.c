/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_of_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 09:12:53 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/03/14 09:12:53 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include <stdlib.h>

void	case_of_2(t_stack *a)
{
	int	*array;
	int	i;

	i = -1;
	array = get_array(a);
	if (array[0] < array[1])
		ft_printf("sa\n");
}

int	*get_array(t_stack *a)
{
	int	i;
	int	*array;

	i = -1;
	array = malloc(sizeof(int) * (a->tamanho));
	while (++i < a->tamanho)
		array[i] = a->stack[i];
	return (array);
}

void	final_movement(t_stack *a, t_stack *b, int mid_point, int chunks)
{
	while ((a->top - 1) > (b->top / chunks))
	{
		if (a->stack[a->top] < mid_point)
			pb(a, b);
		else
			ra(a, true);
	}
}
