/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:19:19 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/08 15:23:29 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*st1;
	unsigned const char	*st2;
	size_t				i;

	st1 = s1;
	st2 = s2;
	i = 0;
	while (i < n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i ++;
	}
	if (i < n)
		return (st1[i] - st2[i]);
	return (0);
}
