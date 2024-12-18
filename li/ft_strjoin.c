/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:26:39 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/05 11:43:28 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s3;
	int		i;
	int		j;
	char	*s3;

	i = 0;
	j = 0;
	len_s3 = ft_strlen(s1) + ft_strlen(s2);
	s3 = malloc(sizeof(char) * len_s3 + 1);
	if (s3 == NULL)
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i ++;
	}
	while (s2[j])
	{
		s3[i + j] = s2[j];
		j ++;
	}
	s3[i + j] = '\0';
	return (s3);
}
