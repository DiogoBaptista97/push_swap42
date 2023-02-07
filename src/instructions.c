/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:02 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/20 10:39:03 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check if is digit
bool	checkdigit(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!((argv[i][j] >= '0' && argv[i][j] <= '9')
				|| argv[i][j] == '-' || argv[i][j] == '+'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_isempty(t_stack *s)
{
	if (s->top == -1)
		return (true);
	else
		return (false);
}

//check if is full
bool	ft_isfull(t_stack *s)
{
	if (s->top == s->tamanho - 1)
		return (true);
	else
		return (false);
}

void	push(t_stack *s, int n)
{
	if (!ft_isfull(s))
	{
		s->top++;
		s->stack[s->top] = n;
	}
	else
		return ;
}

int	pop(t_stack *s)
{
	int	n;

	if (!ft_isempty(s))
	{
		n = s->stack[s->top];
		s->top--;
		return (n);
	}
	else
	{
		ft_printf("error, you noob, you can't pop a empty stack");
		return (EXIT_FAILURE);
	}
}

bool	ft_is_sorted(t_stack *a)
{
	int	i;

	i = -1;
	while (++i < a->tamanho)
	{
		if (a->stack[i] > a->stack[i + 1])
			return (false);
	}
	return (true);
}
