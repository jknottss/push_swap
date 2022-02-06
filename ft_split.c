/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:18:55 by                   #+#    #+#             */
/*   Updated: 2021/10/14 18:42:41 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_words(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static void	*ft_memfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return ((void *) 0);
}

static char	*ft_arr_build(const char *s, int start, int stop)
{
	char	*str;

	str = ft_substr(s, start, stop - start);
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	**ft_valid(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = ft_calloc(ft_words(s, c) + 1, sizeof(char *));
	if (!res)
		return (NULL);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		start;
	char	**res;

	i = -1;
	j = -1;
	start = -1;
	res = ft_valid(s, c);
	if (!res)
		return (NULL);
	while (s[++i])
	{
		if (s[i] != c && start == -1)
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0') && start != -1)
		{
			res[++j] = ft_arr_build(s, start, i + 1);
			if (res[j] == NULL)
				return (ft_memfree(res));
			start = -1;
		}
	}
	return (res);
}
