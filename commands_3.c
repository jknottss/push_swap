/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_valid(t_list *stack_a)
{
	while (stack_a->n)
	{
		if (stack_a->nbr > stack_a->n->nbr)
			return (1);
		stack_a = stack_a->n;
	}
	return (0);
}

void	ft_push_values_on_stack(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;

	stack_a = NULL;
	i = argc - 1;
	while (i > 0)
	{
		if (ft_strlen(argv[i]) == 1)
			ft_push_to_front(&stack_a, ft_atoi(argv[i]));
		else if (ft_strlen(argv[i]) > 1)
			ft_parse_string(&argv[i], &stack_a);
		else
			ft_error();
		i--;
	}
	if (ft_size(&stack_a) == 1)
		exit(1);
	ft_repeat_values_valid(stack_a);
	i = ft_sort_valid(stack_a);
	if (i == 0)
		exit(1);
	ft_sort_type(stack_a);
}
