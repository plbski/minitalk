/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 13:33:43 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/10 15:48:49 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i ;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	if (!lst)
		return (0);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i ++;
	}
	return (i + 1);
}
