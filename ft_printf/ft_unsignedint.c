/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayadouay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:56:56 by ayadouay          #+#    #+#             */
/*   Updated: 2024/11/28 20:56:58 by ayadouay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_int(unsigned int n, int fd)
{
	long	num;
	char	arr[10];
	int		i;
	int		len;

	len = 0;
	num = n;
	i = 0;
	if (num == 0)
		len += write(fd, "0", 1);
	while (num > 0)
	{
		arr[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	i = i - 1;
	while (i >= 0)
	{
		len += ft_putchar_fd(arr[i], fd);
		i--;
	}
	return (len);
}
