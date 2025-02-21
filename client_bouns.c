/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bouns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:22:16 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/21 13:23:00 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

int		g_confermation = 0;

void	error_pid(void)
{
	ft_putstr_fd("This PID Not found !", 1);
	exit(1);
}

void	print_msg(int sig)
{
	if (sig == SIGUSR2)
	{
		g_confermation = 1;
		write(1, "The message was sent successfully.\n", 36);
	}
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
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		c = (unsigned char)str[i];
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
		if (pid < 0 || pid > 4194304)
		{
			ft_putstr_fd("The provided PID is outside the valid range!\n", 1);
			exit(1);
		}
		signal(SIGUSR2, print_msg);
		get_8_bits(pid, av[2]);
		while (g_confermation == 0)
			;
	}
	else
	{
		ft_putstr_fd("Please provide exactly 2 arguments!\n", 1);
		exit(1);
	}
	return (0);
}
