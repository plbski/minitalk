/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:55:42 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/10 11:51:42 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
// #include <stdio.h>

static char	*ft_nb(char *itoa, long n, int i)
{
	itoa[i] = '\0';
	while (n > 0)
	{
		i --;
		itoa[i] = (n % 10) + 48;
		n = n / 10;
	}
	return (itoa);
}

static int	nbcount(long n, int i)
{
	while (n != 0)
	{
		i ++;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i ;
	long	num;
	char	*itoa;
	int		np;

	num = n;
	i = 0;
	if (n <= 0)
	{
		num = -(long)n;
		i = 1;
	}
	np = n < 0;
	i = nbcount(n, i);
	itoa = malloc(sizeof(char) * (i + 1));
	if (itoa == NULL)
		return (NULL);
	if (num == 0)
		itoa[0] = '0';
	else if (np)
		itoa[0] = '-';
	return (ft_nb(itoa, num, i));
}
