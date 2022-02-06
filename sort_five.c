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

void	ft_sort_five_el(t_list **stack_a)
{
	t_list	*stack_b;

	pb(stack_a, &stack_b, 1);
	ft_sort_four_el(stack_a);
	if (stack_b->nbr < (*stack_a)->nbr)
	{
		pa(stack_a, &stack_b, 1);
		return ;
	}
	if (stack_b->nbr > (*stack_a)->n->n->n->nbr)
	{
		pa(stack_a, &stack_b, 1);
		ra(stack_a, 1);
		return ;
	}
	ft_sort_five_el_2(stack_a, stack_b);
}

void	ft_sort_five_el_2(t_list **a, t_list *b)
{
	int	i;

	i = -1;
	while (++i <= 4)
	{
		if (b->nbr > (*a)->nbr && b->nbr < (*a)->n->nbr)
		{
			pa(a, &b, 1);
			sa(a, 1);
			break ;
		}
		else if (b->nbr > (*a)->n->n->n->nbr)
		{
			ft_move_case_2(a, b);
			return ;
		}
		else if (b->nbr > (*a)->n->n->nbr && b->nbr < (*a)->n->n->n->nbr)
		{
			ft_move_case_3(a, b);
			return ;
		}
		else
			ra(a, 1);
	}
	ft_sort_a(a);
}

void	ft_move_case_2(t_list **a, t_list *stack_b)
{
	pa(a, &stack_b, 1);
	ra(a, 1);
}

void	ft_move_case_3(t_list **stack_a, t_list *stack_b)
{
	rra(stack_a, 1);
	pa(stack_a, &stack_b, 1);
	ra(stack_a, 1);
	ra(stack_a, 1);
}

void	ft_sort_a(t_list **a)
{
	while (ft_sort_valid(*a))
		rra(a, 1);
}
