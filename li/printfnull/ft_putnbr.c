/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:37:50 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/18 14:44:59 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putaddr(size_t ptr)
{
	ft_putstr ("0x");
	return (ft_pnb(ptr, "0123456789abcdef", 0, 16) + 2);
}

int	ft_pnb(size_t n, const char *base, int count, size_t len)
{
	int	test;

	if (n >= len)
		count = ft_pnb(n / len, base, count, len);
	test = ft_putchar(base[n % len]);
	if (test == -1)
		return (-1);
	count += test;
	return (count);
}

int	ft_putnbr(int n, int count)
{
	long	num;
	int		test;

	num = n ;
	if (num < 0)
	{
		num *= -1;
		count += ft_putchar('-');
	}
	if (num >= 10)
		count = ft_putnbr(num / 10, count);
	test = ft_putchar((num % 10) + '0');
	if (test == -1)
		return (-1);
	count += test;
	return (count);
}
