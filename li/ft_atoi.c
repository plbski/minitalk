/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:13:03 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/08 09:42:35 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			np;
	long int	num;

	i = 0;
	np = 1;
	num = 0;
	while ((str[i] == 32) || ((str[i] >= 9) && (str[i] <= 13)))
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			np = -1;
		i ++;
	}
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		num = (str[i] - 48) + (num * 10);
		i ++;
	}
	return (num * np);
}
