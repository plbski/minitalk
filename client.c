/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:09:21 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/30 14:13:18 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack;

void	handler_ack(int sig)
{
	if (sig == SIGUSR1)
		g_ack = 1;
}

void	send_signal(unsigned char message, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (message & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(30);
		i++;
	}
}

void	send_message(unsigned char *message, int pid)
{
	int	i;

	i = 0;
	g_ack = 0;
	while (message[i])
	{
		if (i > 0 && i % 2046 == 0)
			usleep(3000);
		send_signal(message[i], pid);
		i ++;
	}
	send_signal('\0', pid);
	while (g_ack == 0)
		pause();
	ft_printf("message recu par le serveur \n");
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_handler = handler_ack;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (argc != 3)
	{
		ft_printf("Erreur : nombre d'arguments invalide\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (kill(pid, 0) == -1)
	{
		ft_printf("Erreur : PID invalide\n");
		return (1);
	}
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "Erreur sigaction\n", 16);
		exit(1);
	}
	send_message((unsigned char *)argv[2], pid);
	return (0);
}
