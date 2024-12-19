
#ifndef MINITALK_H
# define MINITALK_H

# include "li/libft.h"
# include "signal.h"
# include "stdlib.h"
# include "unistd.h"

typedef struct{
    char					buffer[2048];
    int						index;
    unsigned				char current_char;
    int						bit_count;
    int						message_complete;
    volatile sig_atomic_t	processing;
	pid_t					client_pid;
} MessageContext;

#endif