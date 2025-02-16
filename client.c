/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:34:03 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/16 10:24:19 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"

void	error_pid(int *bits)
{
	ft_putstr_fd("This PID Not found !", 1);
	free(bits);
	exit(1);
}

void	ft_send_bit(int server_pid, int *bits)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (bits[j] == 1)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				error_pid(bits);
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				error_pid(bits);
		}
		j++;
		usleep(100);
	}
	free(bits);
}

void	get_8_bits(int server_pid, char *str)
{
	int	*bits;
	int	i;

	i = 0;
	while (str[i])
	{
		bits = char_to_binary(str[i]);
		if (!bits)
			return ;
		ft_send_bit(server_pid, bits);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			exit(1);
		get_8_bits(pid, av[2]);
	}
	else
		exit(1);
	return (0);
}
