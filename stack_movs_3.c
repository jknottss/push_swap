/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movs_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a, int print_action)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_size(stack_a) < 2)
		return ;
	tmp = (*stack_a);
	last = (*stack_a);
	while ((*last).n->n)
		last = last->n;
	(*last).n->n = tmp;
	(*stack_a) = (*last).n;
	last->n = NULL;
	if (print_action)
		write(1, "rra\n", 4);
}

void	rrb(t_list **stack_b, int print_action)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_size(stack_b) < 2)
		return ;
	tmp = (*stack_b);
	last = (*stack_b);
	while ((*last).n->n)
		last = last->n;
	(*last).n->n = tmp;
	(*stack_b) = (*last).n;
	last->n = NULL;
	if (print_action)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
