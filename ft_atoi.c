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

int	ft_atoi(const char *str)
{
	long			res;
	int				count;
	int				sing;
	char			*s;

	res = 0;
	sing = 1;
	s = (char *) str;
	count = 0;
	while (s[count] == '+' || s[count] == '-')
	{
		if (s[count] == '-')
			sing = -1;
		count++;
	}
	if (!(s[count] > 47 && s[count] < 58))
		ft_error();
	while (s[count] > 47 && s[count] < 58)
	{
		res = (res * 10) + (s[count] - '0');
		count++;
	}
	if (res > INT32_MAX || res < INT32_MIN)
		ft_error();
	return (res * sing);
}
