/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:39:02 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/30 14:23:43 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_MessageContext	g_context = {0};

void	reset_buffer(int i)
{
	(void)i;
	ft_memset(g_context.buffer, 0, g_context.index);
	g_context.index = 0;
	g_context.message_complete = 0;
}

void	handle_message_reception(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_context.client_pid = info->si_pid;
	if (sig == SIGUSR1)
		g_context.current_char |= (1 << g_context.bit_count);
	else
		g_context.current_char &= ~(1 << g_context.bit_count);
	g_context.bit_count++;
	if (g_context.bit_count == 8)
	{
		g_context.buffer[g_context.index++] = g_context.current_char;
		if (g_context.current_char == '\0' || g_context.index >= 2046)
		{
			g_context.buffer[g_context.index] = '\0';
			write(1, g_context.buffer, g_context.index);
			reset_buffer(2);
			if (g_context.current_char == '\0')
			{
				ft_printf("\n");
				kill(g_context.client_pid, SIGUSR1);
			}
		}
		g_context.bit_count = 0;
		g_context.current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	sigset_t			block_mask;

	sa.sa_sigaction = handle_message_reception;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigfillset(&block_mask);
	sa.sa_mask = block_mask;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Erreur sigaction\n", 16);
		exit(1);
	}
	ft_printf("PID : %d\n", getpid());
	while (1)
		pause();
	return (0);
}
