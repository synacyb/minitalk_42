/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:34:03 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/14 12:02:34 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "minitalk.h"
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void	send_string(int server_pid, char *str)
{
	int	*bits;
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		bits = char_to_binary(str[i]);
		if (!bits)
			return ;
		j = 0;
		while (j < 8)
		{
			if (bits[j] == 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			j++;
			usleep(100);
		}
		free(bits);
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
		send_string(pid, av[2]);
	}
	else
		exit(1);
	return (0);
}
