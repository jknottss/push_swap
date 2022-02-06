/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_list **stack)
{
	int		max_value;
	t_list	*tmp;

	tmp = (*stack);
	max_value = tmp->index;
	while (tmp)
	{
		if (max_value < tmp->index)
			max_value = tmp->index;
		tmp = tmp->n;
	}
	return (max_value);
}

int	*ft_list_to_arr(t_list *stack_a, int arr_length)
{
	t_list	*tmp;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * arr_length);
	tmp = stack_a;
	i = 0;
	while (tmp)
	{
		arr[i] = tmp->nbr;
		i++;
		tmp = tmp->n;
	}
	return (arr);
}

int	*ft_bubble_sort_array(t_list *stack_a)
{
	int		tmp;
	int		*arr;
	int		i;
	int		j;

	i = -1;
	j = 0;
	arr = ft_list_to_arr(stack_a, ft_size(&stack_a));
	while (++i < (ft_size(&stack_a) - 1))
	{
		while (j < (ft_size(&stack_a) - 1) - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		j = 0;
	}
	return (arr);
}

void	ft_stack_index(int *arr, t_list *stack_a)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = stack_a;
	while (tmp)
	{
		tmp->index = ft_arr_nbr(arr, tmp->nbr);
		tmp = tmp->n;
		i++;
	}
	free(arr);
}
