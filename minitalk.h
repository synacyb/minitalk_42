/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:45:58 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/10 11:47:59 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/types.h>

// struct data !
typedef struct signal_handler_data
{
	int		j;
	int		r;
	char	c;
}	t_signal;

int	*char_to_binary(unsigned char c);

#endif
