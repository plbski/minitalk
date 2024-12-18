/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbopp <cbopp@student.42lausanne.ch>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:12:43 by cbopp             #+#    #+#             */
/*   Updated: 2024/12/02 15:25:06 by cbopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(void *lst, char type, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return ;
	while (i < size)
	{
		if (type == 'd')
			ft_printf("%d\n", ((int *)lst)[i]);
		else if (type == 'i')
			ft_printf("%i\n", ((int *)lst)[i]);
		else if (type == 'c')
			ft_printf("%c\n", ((char *)lst)[i]);
		else if (type == 'p')
			ft_printf("%p\n", &((void **)lst)[i]);
		else if (type == 'u')
			ft_printf("%u\n", ((unsigned int *)lst)[i]);
		else if (type == 'x')
			ft_printf("%x\n", ((unsigned int *)lst)[i]);
		i++;
	}
	ft_printf("\n");
}
