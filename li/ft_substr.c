/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:15:25 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/09 15:20:16 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (start >= (unsigned int)ft_strlen(s))
	{
		s2 = malloc(sizeof(char));
		if (s2)
			s2[0] = '\0';
		return (s2);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[start + i];
		i ++;
	}
	s2[i] = '\0';
	return (s2);
}
