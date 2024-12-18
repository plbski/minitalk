/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 09:55:25 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/05 11:47:36 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (i > 0 && s[i - 1] != c)
				count++;
		}
		i++;
	}
	if (i > 0 && s[i - 1] != c)
		count++;
	return (count);
}

static void	ft_free(char **split, int j)
{
	while (j > 0)
	{
		free(split[--j]);
	}
	free(split);
}

static char	**loop(char **split, char const*s, char c, int i)
{
	int	start;
	int	j;

	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i ++;
		if (s[i])
		{
			start = i;
			while (s[i] != c && s[i])
				i ++;
			split[j] = ft_substr(s, start, i - start);
			if (split[j] == NULL)
			{
				ft_free(split, j);
				return (NULL);
			}
			j ++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	split = malloc(sizeof(char *) * (count(s, c) + 1));
	if (split == NULL)
		return (NULL);
	split = loop(split, s, c, i);
	if (split == NULL)
		return (NULL);
	return (split);
}
