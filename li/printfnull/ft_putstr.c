/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:28:10 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/18 14:21:53 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i ;
	int	test;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		test = ft_putchar(s[i]);
		if (test == -1)
			return (-1);
		i += test;
	}
	return (i);
}
