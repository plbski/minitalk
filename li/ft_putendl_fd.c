/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 10:01:21 by cbopp             #+#    #+#             */
/*   Updated: 2024/10/03 10:08:49 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
