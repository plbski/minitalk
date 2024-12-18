/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:54:33 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/10 16:09:24 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	cc;

	cc = (char) c;
	i = ft_strlen(s);
	if (s[i] == cc)
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (s[i - 1] == cc)
			return ((char *)&s[i - 1]);
		i --;
	}
	return (NULL);
}
