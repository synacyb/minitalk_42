#include "libft/libft.h"
#include "minitalk.h"

int	g_signal_received = 0;

void	error_pid(void)
{
	ft_putstr_fd("This PID Not found !", 1);
	exit(1);
}

void	print_msg(int sig)
{
	(void)sig;
	g_signal_received = 1;
	write(1, "The message was sent successfully.\n", 36);
}
void	ft_send_bit(int server_pid, unsigned char c)
{
	int	j;

	j = 8;
	while (j--)
	{
        if ((c >> j) & 1)
        {
            if (kill(server_pid, SIGUSR1) == -1)
				error_pid();
        }
        else
        {
            if (kill(server_pid, SIGUSR2) == -1)
				error_pid();
        }
		usleep(100);
	}
}

void	get_8_bits(int server_pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
        unsigned char c = (unsigned char)str[i];
		ft_send_bit(server_pid, c);
		i++;
	}
	ft_send_bit(server_pid, '\0');
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			exit(1);
		signal(SIGUSR2, print_msg);
		get_8_bits(pid, av[2]);
		while (!g_signal_received);
	}
	else
		exit(1);
	return (0);
}