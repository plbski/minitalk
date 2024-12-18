/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:50:46 by plbuet            #+#    #+#             */
/*   Updated: 2024/10/10 15:59:05 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t size)
{
	unsigned char	*s1;
	size_t			i;

	i = 0;
	s1 = ptr;
	while (i < size)
	{
		s1[i] = value;
		i ++;
	}
	return (ptr);
}
