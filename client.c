/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <pbuet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:09:21 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/18 18:05:11 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_signal(unsigned char message, int pid)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (message & (1 << i))
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
		usleep(50);
        i++;
    }
}

void send_message(unsigned char *message, int pid)
{
    int i;

    i = 0;
    while (message[i])
    {
        send_signal(message[i], pid);
		if (i % 2047 == 0)
		{
			send_signal('\0', pid);
			usleep(400);
		}
		i ++;
    }
	send_signal('\0', pid);
    send_signal(0x04, pid);
	usleep(400);
}

int main(int argc, char **argv)
{
    int pid;

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
    send_message((unsigned char *)argv[2], pid);
    return (0);
}
