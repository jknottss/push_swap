/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_movs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int print_action)
{
	t_list	*tmp;

	if (ft_size(stack_a) < 2)
		return ;
	tmp = (*stack_a)->n;
	(*stack_a)->n = (*stack_a)->n->n;
	tmp->n = (*stack_a);
	(*stack_a) = tmp;
	if (print_action)
		write(1, "sa\n", 3);
}

void	sb(t_list **stack_b, int print_action)
{
	t_list	*tmp;

	if (ft_size(stack_b) < 2)
		return ;
	tmp = (*stack_b)->n;
	(*stack_b)->n = (*stack_b)->n->n;
	tmp->n = (*stack_b);
	(*stack_b) = tmp;
	if (print_action)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}

void	pa(t_list **stack_a, t_list **stack_b, int print_action)
{
	t_list	*tmp;

	if (!*stack_b)
		return ;
	tmp = (*stack_b);
	(*stack_b) = tmp->n;
	tmp->n = (*stack_a);
	(*stack_a) = tmp;
	if (print_action)
		write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b, int print_action)
{
	t_list	*tmp;

	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->n;
	tmp->n = (*stack_b);
	(*stack_b) = tmp;
	if (print_action)
		write(1, "pb\n", 3);
}
