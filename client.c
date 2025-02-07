#include <signal.h>
#include "libft/libft.h"
#include "minitalk.h"

void send_string(int server_pid, char *str)
{
	int *bits = NULL;
	int *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		tmp = bits;
		bits = char_to_binary(str[i]);
		while (bits[j])
		{
			if (bits[j] == SIGUSR1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			j++;
		}
		if (tmp)
			free(tmp);
	}
	
}

int main(int ac, char **av) 
{
	int *num;
	int i;

	num = malloc(sizeof(int) * 8);
	i = 0;
	if (ac == 3)
	{
		pid_t	pid;

		pid = ft_atoi(av[1]);
		if (pid < 0)
			exit (1);
		send_string(pid, av[2]);
	}
	else
		exit (1);
}