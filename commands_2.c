/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_repeat_values_valid(t_list *stack_a)
{
	t_list	*tmp;
	t_list	*tmp_for_val;
	int		val;
	int		i;
	int		stack_size;

	i = 0;
	stack_size = ft_size(&stack_a);
	tmp_for_val = stack_a;
	while (i != stack_size)
	{
		val = tmp_for_val->nbr;
		tmp = tmp_for_val->n;
		while (tmp)
		{
			if (val == tmp->nbr)
				ft_error();
			tmp = tmp->n;
		}
		tmp_for_val = tmp_for_val->n;
		i++;
	}
}

int	ft_size(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*stack);
	while (tmp)
	{
		tmp = tmp->n;
		i++;
	}
	return (i);
}

void	ft_parse_string(char **str, t_list **stack_a)
{
	char	**res;
	int		i;

	res = ft_split(*str, ' ');
	i = ft_ptrcap(res);
	while (i >= 0)
	{
		ft_push_to_front(stack_a, ft_atoi(res[i]));
		i--;
	}
	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
