/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:41:49 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/10 15:37:20 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*save_lst;

	if (!lst || !del || !f)
		return (NULL);
	save_lst = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstdelone(new, del);
			return (NULL);
		}
		ft_lstadd_back(&save_lst, new);
		lst = lst->next;
	}
	return (save_lst);
}
