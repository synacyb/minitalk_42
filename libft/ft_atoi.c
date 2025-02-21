/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:45 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/21 13:16:47 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	desiplay_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	add_defult_data(t_atoi *data)
{
	data->r = 0;
	data->signe = 1;
	data->len = 0;
}

void	range_error(void)
{
	write(2, "PID is outside the valid range!", 31);
	exit(1);
}

int	ft_atoi(const char *nptr)
{
	t_atoi	data;

	add_defult_data(&data);
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			data.signe *= -1;
		nptr++;
	}
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
	{
		data.r = data.r * 10 + (*nptr - 48);
		data.len++;
		nptr++;
	}
	if (*nptr)
		desiplay_error();
	else if (data.len > 7)
		range_error();
	data.r = data.r * data.signe;
	return (data.r);
}
