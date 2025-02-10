/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   service.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:17:02 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/10 11:52:33 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"
#include "ft_printf/ft_printf.h"

void	signal_handler(int sig)
{
	static int	bits[8];
	static int	i;
	t_signal	data;

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
		data.c = (char)data.r;
		write(1, &data.c, 1);
		i = 0;
	}
}

int	main(int ac, char **av)
{
	int	get;

	(void)av;
	if (ac == 1)
	{
		get = getpid();
		ft_printf("Server PID: %d\n", get);
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		while (1)
			pause();
	}
	return (0);
}
