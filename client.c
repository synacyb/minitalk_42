/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:34:03 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/21 11:42:59 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	error_pid(void)
{
	ft_putstr_fd("This PID Not found !", 1);
	exit(1);
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
	ft_send_bit(server_pid, '\n');
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
		get_8_bits(pid, av[2]);
	}
	else
	{
		ft_putstr_fd("Please provide exactly 2 arguments!\n", 1);
		exit(1);
	}
	return (0);
}
