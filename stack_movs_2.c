/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movs_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int print_action)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_size(stack_a) < 2)
		return ;
	tmp = (*stack_a);
	last = (*stack_a);
	(*stack_a) = (*stack_a)->n;
	while (tmp->n)
		tmp = tmp->n;
	tmp->n = last;
	tmp->n->n = NULL;
	if (print_action)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack_b, int print_action)
{
	t_list	*tmp;
	t_list	*last;

	if (ft_size(stack_b) < 2)
		return ;
	tmp = (*stack_b);
	last = (*stack_b);
	while ((*last).n)
		last = (*last).n;
	last->n = tmp;
	(*stack_b) = (*tmp).n;
	(*tmp).n = NULL;
	if (print_action)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
