/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:30:42 by clcarre           #+#    #+#             */
/*   Updated: 2022/04/19 13:55:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_contador_ptr(unsigned long long n)
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

void	ft_write_ptr(unsigned long long n, int fd, char *base)
{
	if (n >= 16)
	{
		ft_write_ptr(n / 16, fd, base);
		ft_write_ptr(n % 16, fd, base);
	}
	else
		write (fd, &base[n], 1);
}

int	ft_put_ptr(unsigned long long ptr, int fd)
{
	int	c;

	write (fd, "0x", 2);
	c = 2;
	if (ptr == 0)
	{
		write (fd, "0", 1);
		c++;
	}
	else
	{
		ft_write_ptr(ptr, 1, "0123456789abcdef");
		c = c + ft_contador_ptr(ptr);
	}
	return (c);
}
