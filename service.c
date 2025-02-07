#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

void signal_handler(int sig) 
{
    // Decode the signal and reconstruct the string
}

int main()
{
    ft_printf("Server PID: %d\n", getpid());
    signal(SIGUSR1, signal_handler);
    signal(SIGUSR2, signal_handler);
    while (1) {
        pause();
    }
    return 0;
}