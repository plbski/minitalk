/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:39:02 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/13 15:54:38 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
char *ft_realloc(char *s, int size, char c)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = malloc(sizeof(char) * size + 1);
	if (!s2)
		return (NULL);
	if (!s)
	{
		s2[0] = c;
		return (s2);
	}
	while (i < size)
	{
		s2[i] = s[i];
		i ++;
	}
	free(s);
	s2[i] = c;
	return (s2);
}

void	build_message(char c)
{
	static char	*message = NULL;
	static int	i = 0;

	message = ft_realloc(message, i, c);
	if (!message)
		return;
	if (c == '\0')
	{
		ft_printf("%s\n", message);
		free (message);
		message = NULL;
		i = -1;
	}
	i ++;
}
void	recep_message(int sig)
{
	static int				i;
	static unsigned char	c;

	if (sig == SIGUSR1)
		c |= (1 << i);
	i ++;
	if (i == 8)
	{
		build_message(c);
		i = 0;
		c = 0;
	}
}
int	main()
{
	struct sigaction	sa;

    sa.sa_flags = 0;
	sa.sa_handler = recep_message;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}