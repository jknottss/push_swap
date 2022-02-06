/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
		exit(1);
	ft_push_values_on_stack(argc, argv);
	return (0);
}

void	ft_sort_type(t_list *stack_a)
{
	if (ft_size(&stack_a) == 2 && stack_a->nbr > stack_a->n->nbr)
		sa(&stack_a, 1);
	else if (ft_size(&stack_a) == 3)
		ft_sort_tree_el(&stack_a);
	else if (ft_size(&stack_a) == 4)
		ft_sort_four_el(&stack_a);
	else if (ft_size(&stack_a) == 5)
		ft_sort_five_el(&stack_a);
	else if (ft_size(&stack_a) > 5)
		ft_sort(stack_a);
	ft_free_mem(stack_a);
	exit(0);
}
