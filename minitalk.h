/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbuet <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:13:45 by pbuet             #+#    #+#             */
/*   Updated: 2024/12/30 14:17:29 by pbuet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "li/libft.h"
# include "signal.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct s_message{
	char					buffer[2048];
	int						index;
	unsigned char			current_char;
	int						bit_count;
	int						message_complete;
	volatile sig_atomic_t	processing;
	pid_t					client_pid;
}	t_MessageContext;

#endif
