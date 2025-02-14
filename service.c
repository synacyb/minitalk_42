/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:17:02 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/14 11:36:29 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf/ft_printf.h"
#include "minitalk.h"

void	reset_bits(int *arr)
{
	int	i;
	i = 0;

	while(i < 8)
		arr[i++] = 0;
}
void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static int	bits[8];
	static int	i;
	t_signal	data;
	int		current_pid;
	static int	last_pid;
	(void)context;
	current_pid = info->si_pid;
	if(last_pid != info->si_pid)
	{
		reset_bits(bits);
		i = 0;
		last_pid = info->si_pid;
	}
	if (sig == SIGUSR1)
		bits[i] = 1;
	else
		bits[i] = 0;
	i++;
	if (i == 8)
	{
		data.r = 0;
		data.j = 0;
		while (data.j < 8)
			data.r = data.r * 2 + bits[data.j++];
		data.c = (unsigned char)data.r;
		write(1, &data.c, 1);
		i = 0;
		reset_bits(bits);
	}
}

int	main(int ac, char **av)
{
	int	get;

	(void)av;
	if (ac == 1)
	{
		get = getpid();
		struct sigaction sa;

		ft_printf("Server PID: %d\n", get);
   		sa.sa_sigaction = signal_handler;
    		sa.sa_flags = SA_SIGINFO;
    		sigemptyset(&sa.sa_mask);

    		sigaction(SIGUSR1, &sa, NULL);
   	 	sigaction(SIGUSR2, &sa, NULL);
		while (1);
	}
	return (0);
}
