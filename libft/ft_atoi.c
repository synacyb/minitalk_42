/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <ayadouay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:30:45 by ayadouay          #+#    #+#             */
/*   Updated: 2025/02/07 16:35:32 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	desiplay_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
int	ft_atoi(const char *nptr)
{
	long	r;
	int		signe;

	r = 0;
	signe = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			signe *= -1;
		nptr++;
	}
	while (*nptr != '\0' && (*nptr >= '0' && *nptr <= '9'))
	{
		r = r * 10 + (*nptr - 48);
		if (r > 2147483647 || r < -2147483648)
			desiplay_error();
		nptr++;
	}
	if (*nptr)
		desiplay_error();
	r = r * signe;
	return (r);
}
