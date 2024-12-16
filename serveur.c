/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:39:02 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/16 15:28:03 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
void	build_message(char c)
{
	static char	*message = NULL;
	static int	i = 0;

	if (message == NULL)
	{
		message = malloc(9999);
		if (!message)
			exit(1);
		ft_memset(message, 0, 9999);
	}
	message[i] = c;
	i ++;
	if (i == 4095 || c == '\0')
	{
		ft_printf("%s", message);
		free(message);
		message = NULL;
		i = 0;
		if (c == '\0')
			ft_printf("\n");
	}
}
void	recep_message(int sig)
{
	static int				i = 0;
	static unsigned char	c = 0;

	if (sig == SIGUSR1)
		c |= (1 << i);
	else
		c &= ~(1 << i);
	i ++;
	if (i == 8)
	{
		build_message(c);
		i = 0;
		c = 0;
	}
}
int main()
{
    struct sigaction sa;
    
    sa.sa_handler = recep_message;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1 || 
        sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        perror("Erreur sigaction");
        exit(1);
    }

    ft_printf("PID : %d\n", getpid());

    while (1)
        pause();

    return 0;
}