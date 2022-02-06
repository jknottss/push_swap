/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	do_commands(t_list **stack_a, t_list **stack_b, char *command)
{
	if (!(ft_strcmp(command, "sa\n")))
		sa(stack_a, 0);
	else if (!(ft_strcmp(command, "sb\n")))
		sb(stack_b, 0);
	else if (!(ft_strcmp(command, "ss\n")))
		ss(stack_a, stack_b);
	else if (!(ft_strcmp(command, "pa\n")))
		pa(stack_a, stack_b, 0);
	else if (!(ft_strcmp(command, "pb\n")))
		pb(stack_a, stack_b, 0);
	else if (!(ft_strcmp(command, "ra\n")))
		ra(stack_a, 0);
	else if (!(ft_strcmp(command, "rb\n")))
		rb(stack_b, 0);
	else if (!(ft_strcmp(command, "rr\n")))
		rr(stack_a, stack_b);
	else if (!(ft_strcmp(command, "rra\n")))
		rra(stack_a, 0);
	else if (!(ft_strcmp(command, "rrb\n")))
		rrb(stack_b, 0);
	else if (!(ft_strcmp(command, "rrr\n")))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	ft_parse(t_list *stack_a)
{
	t_list	*stack_b;
	char	*command;

	stack_b = NULL;
	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		if (!do_commands(&stack_a, &stack_b, command))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		free(command);
	}
	if (!ft_sort_valid(stack_a) && ft_size(&stack_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	int		i;

	if (argc == 1)
		exit(1);
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
	ft_parse(stack_a);
	return (0);
}

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
