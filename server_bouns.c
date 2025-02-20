#include "ft_printf/ft_printf.h"
#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static char	c;
	static int	i;
	static int	last_pid;

	(void)context;
	if (last_pid != info->si_pid)
	{
		c = 0;
		i = 0;
		last_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
	{
		c = c << 1 | 1;
	}
	else
		c = c << 1;
	i++; 
	if (i == 8)
	{
		write(1, &c, 1);
		c = 0;
		i = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				get;

	(void)av;
	if (ac == 1)
	{
		get = getpid();
		ft_printf("Server PID: %d\n", get);
		sa.sa_sigaction = signal_handler;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		while (1)
		{}
	}
	return (0);
}