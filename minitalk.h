#ifndef MINITALK_H
#define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

// struct of signal_handler !
typedef struct  signal_handler_data
{
    int	bits[8];
    int i;
}t_signal;

int   *char_to_binary(unsigned char c);

#endif