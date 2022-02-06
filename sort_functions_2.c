/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_arr_nbr(int *arr, int i)
{
	int	count;

	count = 0;
	while (arr[count] != i)
		count++;
	return (count);
}

void	ft_move_to_stack_b(t_list **stack_a, int range)
{
	int		i;
	t_list	*stack_b;

	i = 0;
	stack_b = NULL;
	while (*stack_a)
	{
		if (i > 1 && (*stack_a)->index <= i)
		{
			pb(stack_a, &stack_b, 1);
			rb(&stack_b, 1);
			i++;
		}
		else if ((*stack_a)->index <= i + range)
		{
			pb(stack_a, &stack_b, 1);
			i++;
		}
		else if ((*stack_a)->index >= i)
			ra(stack_a, 1);
	}
	ft_move_to_stack_a(&stack_b);
}
