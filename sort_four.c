/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four_el(t_list **stack_a)
{
	t_list	*b;

	pb(stack_a, &b, 1);
	ft_sort_tree_el(stack_a);
	if (b->nbr < (*stack_a)->nbr)
		pa(stack_a, &b, 1);
	else if (b->nbr > (*stack_a)->nbr && b->nbr < (*stack_a)->n->nbr)
	{
		pa(stack_a, &b, 1);
		sa(stack_a, 1);
	}
	else if (b->nbr > (*stack_a)->n->nbr && b->nbr < (*stack_a)->n->n->nbr)
	{
		rra(stack_a, 1);
		pa(stack_a, &b, 1);
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else
	{
		pa(stack_a, &b, 1);
		ra(stack_a, 1);
	}
}
