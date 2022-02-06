/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jknotts <jknotts@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:19:37 by jknotts           #+#    #+#             */
/*   Updated: 2022/01/10 16:55:35 by jknotts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_front(t_list **begin_list, int nbr)
{
	t_list	*node;

	node = ft_create_el(nbr);
	node->n = *begin_list;
	*begin_list = node;
}

t_list	*ft_create_el(int nbr)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (list);
	list->nbr = nbr;
	list->index = 0;
	list->n = NULL;
	return (list);
}

void	ft_free_mem(t_list *stack)
{
	t_list	*tmp;
	t_list	*delete;

	tmp = stack;
	while (tmp)
	{
		delete = tmp;
		tmp = tmp->n;
		free(delete);
	}
	free(tmp);
}

int	ft_ptrcap(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i - 1);
}
