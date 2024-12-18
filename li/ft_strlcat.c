/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:26:34 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/03 17:22:51 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	if (len_dest >= size)
		return (len_src + size);
	while ((len_dest + i < size - 1) && (src[i]))
	{
		dst[len_dest + i] = src[i];
		i ++;
	}
	dst[len_dest + i] = '\0';
	return (len_dest + len_src);
}
