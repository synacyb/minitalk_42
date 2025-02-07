#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int sig)
{
	static int bits[8];
	static int i = 0;
	int j;
	char c;

	if (sig == SIGUSR1)
		bits[i] = 1; // SIGUSR1 = 1
	else
		bits[i] = 0; // SIGUSR2 = 0

	i++;

	if (i == 8) // When we receive 8 bits, convert to char
	{
		c = 0;
		j = 0;
		while (j < 8)
		{
			c = (c << 1) | bits[j]; // Shift left and add bit
			j++;
		}
		write(1, &c, 1); // Print character
		i = 0; // Reset for next char
	}
}

int main()
{
    int get = getpid();
    printf("Server PID: %d\n", get);

    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sa.sa_flags = SA_RESTART;
    sigemptyset(&sa.sa_mask);

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1)
        pause(); // Wait for signals

    return 0;
}
