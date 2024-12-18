/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:43:15 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/18 14:44:18 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	partition(char conversion, va_list *args)
{
	if (conversion == 'c')
	{
		return (ft_putchar(va_arg(*args, int)));
	}
	else if (conversion == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (conversion == 'p')
	{
		return (ft_putaddr(va_arg(*args, size_t)));
	}
	else if (conversion == 'd' || conversion == 'i')
		return (ft_putnbr(va_arg(*args, int), 0));
	else if (conversion == 'u')
		return (ft_pnb(va_arg(*args, unsigned int), "0123456789", 0, 10));
	else if (conversion == 'x')
		return (ft_pnb(va_arg(*args, unsigned int), "0123456789abcdef", 0, 16));
	else if (conversion == 'X')
		return (ft_pnb(va_arg(*args, unsigned int), "0123456789ABCDEF", 0, 16));
	else if (conversion == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			count;
	int			test;

	va_start(args, format);
	i = 0;
	count = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i ++;
			test = partition(format[i], &args);
			if (test == -1)
				return (-1);
			count += test;
		}
		else
			count += ft_putchar(format[i]);
		i ++;
	}
	return (count);
}
// int main()
// {
// 	int num;
// 	printf(" %d", ft_printf("\n %u la truffe %i %p", -134564645, 0, 2));
// 	printf(" %d",printf("\n %u la truffe %i %p", -134567645, 0, 2));
// 	return (0);
// }
