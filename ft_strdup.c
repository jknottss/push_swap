/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:10:20 by                   #+#    #+#             */
/*   Updated: 2021/10/13 21:39:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strcp(char *dest, char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		dest[count] = str[count];
		count++;
	}
	return (dest);
}

char	*ft_strdup(char *str)
{
	int		count;
	char	*dest;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	dest = ft_calloc(count + 1, sizeof (*str));
	if (dest == NULL)
		return (dest);
	dest = ft_strcp(dest, str);
	return (dest);
}
