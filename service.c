#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void signal_handler(int sig)
{
	static int	bits[8] = {0};
	static int	i = 0;

	if (sig == SIGUSR1)
		bits[i] = 1;
	else
		bits[i] = 0;

	i++;
	if (i == 8)
	{
		int r = 0;
		int j = 0;
		char c;

		while (j < 8)
			r = r * 2 + bits[j++];

		c = (char)r;
		write(1, &c, 1);
		
		i = 0;
	}
}

int main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
	{
		int get = getpid();
		printf("Server PID: %d\n", get);

		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);

		while (1)
			pause();
	}
	return 0;
}

