#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "minitalk.h"

void send_string(int server_pid, char *str)
{
	int *bits;
	int i = 0, j;

	while (str[i])
	{
		bits = char_to_binary(str[i]);
		if (!bits)
			return;
		j = 0;
		while (j < 8)
		{
			if (bits[j] == 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			sleep(1);
			j++;
		}
		free(bits);
		i++;
	}
}

int main(int ac, char **av) 
{
	if (ac == 3)
	{
		pid_t pid = ft_atoi(av[1]);
		if (pid <= 0)
			exit(1);
		send_string(pid, av[2]);
	}
	else
		exit(1);
	return 0;
}
