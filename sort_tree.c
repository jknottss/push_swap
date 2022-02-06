/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tree_el(t_list **a)
{
	while (ft_sort_valid((*a)))
	{
		if ((*a)->nbr < (*a)->n->nbr && (*a)->n->nbr > (*a)->n->n->nbr)
			rra(a, 1);
		else if ((*a)->nbr > (*a)->n->n->nbr && (*a)->n->nbr < (*a)->n->n->nbr)
			ra(a, 1);
		else
			sa(a, 1);
	}
}
