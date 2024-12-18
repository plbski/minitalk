/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:54:55 by plbuet            #+#    #+#             */
/*   Updated: 2024/10/09 14:35:34 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (!src && !dst)
		return (NULL);
	d = (char *)dst;
	s = (const char *)src;
	if (d > s)
		while (len --)
			d[len] = s[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
