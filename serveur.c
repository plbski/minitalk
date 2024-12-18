/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:39:02 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/18 14:43:03 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

// Une seule variable globale pour stocker toutes les informations
typedef struct {
    char buffer[2048];
    int index;
    unsigned char current_char;
    int bit_count;
    int message_complete;
} MessageContext;

MessageContext g_context = {0};

void reset_buffer()
{
    ft_memset(g_context.buffer, 0, g_context.index + 1);
    g_context.index = 0;
    g_context.message_complete = 0;
}

void handle_message_reception(int sig)
{
    if (sig == SIGUSR1)
        g_context.current_char |= (1 << g_context.bit_count);
    else
        g_context.current_char &= ~(1 << g_context.bit_count);
    g_context.bit_count++;
    if (g_context.bit_count == 8)
    {
        g_context.buffer[g_context.index++] = g_context.current_char;
        if (g_context.current_char == '\0' || g_context.index >= 2047)
        {
			g_context.buffer[g_context.index] = '\0';
			ft_printf("%s", g_context.buffer);
			reset_buffer();
			if (g_context.current_char == '\0')
				ft_printf("\n");
        }
		g_context.bit_count = 0;
		g_context.current_char = 0;
    }
}

int main()
{
    struct sigaction sa;

    sa.sa_handler = handle_message_reception;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGUSR1, &sa, NULL) == -1 || 
        sigaction(SIGUSR2, &sa, NULL) == -1)
    {
        write(2, "Erreur sigaction\n", 16);
        exit(1);
    }
    ft_printf("PID : %d\n", getpid());
    while (1)
        pause();
    return 0;
}