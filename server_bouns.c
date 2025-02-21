/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bouns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:28:26 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/21 11:41:54 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf/ft_printf.h"
#include "minitalk.h"

void	check_send_string(pid_t pid, char c)
{
	if (c == '\0')
	{
		write(1, "\n", 1);
		if (kill(pid, SIGUSR2) == -1)
		{
			ft_printf("Errore\n");
			exit(1);
		}
	}
}

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
		check_send_string(last_pid, c);
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
			;
	}
	return (0);
}
