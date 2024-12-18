/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plbuet <plbuet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:13:01 by pbuet             #+#    #+#             */
/*   Updated: 2024/10/08 15:45:39 by plbuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i ;
	char	*s1;

	i = 0;
	if (s == NULL)
		return (NULL);
	s1 = ft_strdup(s);
	if (s1 == NULL)
		return (NULL);
	while (s1[i])
	{
		s1[i] = f(i, s1[i]);
		i ++;
	}
	return (s1);
}
