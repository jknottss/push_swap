/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list *stack_a)
{
	int	*arr;
	int	range;

	range = 15;
	if (ft_size(&stack_a) > 100)
		range = 30;
	arr = ft_bubble_sort_array(stack_a);
	ft_stack_index(arr, stack_a);
	ft_move_to_stack_b(&stack_a, range);
}

int	*ft_index_array(t_list *stack_b, int *arr)
{
	int	i;

	i = -1;
	while (stack_b)
	{
		arr[++i] = stack_b->index;
		stack_b = stack_b->n;
	}
	return (arr);
}

int	ft_side(t_list **stack_b, int max, int stack_b_size)
{
	int	i;
	int	*index_arr;

	index_arr = malloc(sizeof(int) * (stack_b_size + 1));
	if (!index_arr)
		return (0);
	index_arr = ft_index_array(*stack_b, index_arr);
	i = stack_b_size;
	while (index_arr[stack_b_size] != max)
		stack_b_size--;
	i = i - stack_b_size;
	stack_b_size = 0;
	while (index_arr[stack_b_size] != max)
		stack_b_size++;
	free(index_arr);
	if (i < stack_b_size)
		return (1);
	return (0);
}

void	ft_move_to_stack_a(t_list **st_b)
{
	t_list	*stack_a;

	stack_a = NULL;
	while (*st_b)
	{
		if (!*st_b)
			break ;
		if ((*st_b)->index != ft_max(st_b) && \
			!ft_side(st_b, ft_max(st_b), ft_size(st_b)))
			rb(st_b, 1);
		else if ((*st_b)->index != ft_max(st_b) && \
			ft_side(st_b, ft_max(st_b), ft_size(st_b)))
			rrb(st_b, 1);
		else if ((*st_b)->index == ft_max(st_b))
			pa(&stack_a, st_b, 1);
	}
	exit(0);
}
