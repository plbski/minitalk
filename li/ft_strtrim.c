/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:39:52 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/09 16:00:09 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, (int)s1[start]) != NULL)
		start ++;
	end = ft_strlen(s1);
	while (end > start && ft_strrchr(set, (int)s1[end - 1]) != NULL)
		end --;
	s2 = malloc(sizeof(char) * (end - start + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strlcpy(s2, &s1[start], end - start + 1);
	return (s2);
}
