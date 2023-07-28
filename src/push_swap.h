/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraga-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:49 by dbraga-b          #+#    #+#             */
/*   Updated: 2023/01/20 10:39:50 by dbraga-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include"../libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_stack
{
	int	tamanho;
	int	*stack;
	int	top;
}	t_stack;

t_stack	init_stacka(int argc);
t_stack	init_stackb(int argc);

//possivel eliminacao de push and pop
int		getsize(int	*stack);
void	sa(t_stack *stack, bool truesb);
void	sb(t_stack *stack, bool truesb);
void	fill_stacka(t_stack *a, char *argv[]);
bool	checkdigit(char *argv[]);
bool	checkdouble(t_stack *a);
bool	checkdouble_aux(int *array, int n, int size);
bool	ft_isempty(t_stack *s);
bool	ft_isfull(t_stack *s);
void	push(t_stack *s, int n);
int		pop(t_stack *s);
void	pa(t_stack *stacka, t_stack *stackb);
void	pb(t_stack *stacka, t_stack *stackb);
void	ra(t_stack *stack, bool truesa);
void	rb(t_stack *stack, bool truesb);
void	rr(t_stack *stacka, t_stack *stackb);
void	rra(t_stack *stack, bool truesa);
void	rrb(t_stack *stack, bool truesb);
void	rrr(t_stack *stacka, t_stack *stackb);
void	printstacks(t_stack *a, t_stack *b);
void	freestacks(t_stack *stacka, t_stack *stackb);
bool	ft_is_sorted(t_stack *a);
t_stack	*positive_stack(t_stack *a);
int		*sorte_positivo(t_stack *dup, t_stack *a);
int		pos(int num, t_stack *a);
void	case_of_3(t_stack *a);
void	case_of_2(t_stack *a);
void	case_of_5(t_stack *a, t_stack *b);
void	insertion_sort(t_stack *a, t_stack *b);
int		max_int_top(t_stack *b, int max);
//roddix
void	radix_sort(t_stack *a, t_stack *b);
int		max_mum(t_stack *a);
void	simplify_numbers(t_stack *stack, int *sorted_array);
int		*array_to_sort(t_stack *a);
void	sort_final(int	*array, int size);
int		min_int_top(t_stack *a, int min);
int		max_int_top(t_stack *b, int max);
int		min_num(t_stack *b);
void	push_small_to_b_bottom(t_stack *a, t_stack *b, int mid_point);
void	push_small_to_b(t_stack *a, t_stack *b, int mid_point);
void	final_movement(t_stack *a, t_stack *b, int mid_point, int chunks);
int		*get_array(t_stack *a);
void	handle_error_1(char *str);

#endif
