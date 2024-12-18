/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 18:47:48 by plbuet            #+#    #+#             */
/*   Updated: 2024/10/18 14:41:16 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_putnbr(int n, int count);
int	ft_putstr(char *s);
int	ft_putaddr(size_t ptr);
int	ft_putchar(char c);
int	ft_pnb(size_t n, const char *base, int count, size_t len);
int	ft_printf(const char *format, ...);

#endif
