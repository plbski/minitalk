/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:37:50 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/08 09:44:08 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = (long int)n ;
	if (num < 0)
	{
		num *= -1;
		ft_putchar_fd('-', fd);
	}
	if (num >= 10)
	{
		ft_putnbr_fd(num / 10, fd);
	}
	ft_putchar_fd(num % 10 + '0', fd);
}

// int main(void)
// {
//     ft_putnbr_fd(12345, 1);  // Affiche "12345" sur la sortie standard
//     write(1, "\n", 1);
//
//     ft_putnbr_fd(-6789, 1);  // Affiche "-6789" sur la sortie standard
//     write(1, "\n", 1);
//
//     ft_putnbr_fd(-2147483648, 1);  // Affiche "-2147483648"
//     write(1, "\n", 1);
//    
//     return 0;
// }