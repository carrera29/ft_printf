/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_a_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:28:55 by clcarre           #+#    #+#             */
/*   Updated: 2022/04/19 15:00:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_contador_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

void	ft_write_hex(unsigned int n, int fd, char *base)
{
	if (n >= 16)
	{
		ft_dec_a_hex(n / 16, fd, base);
		n = (n % 16);
	}
	if (n < 16)
		write (fd, &base[n], 1);
}

int	ft_dec_a_hex(unsigned int n, int fd, char *base)
{
	if (n == 0)
		write (fd, "0", 1);
	else
		ft_write_hex(n, fd, base);
	return (ft_contador_hex(n));
}