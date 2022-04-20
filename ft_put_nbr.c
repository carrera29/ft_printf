/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarre <clcarrer@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:30:14 by clcarre           #+#    #+#             */
/*   Updated: 2022/04/18 16:31:44 by clcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_contador(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_put_nbr(int n, int fd)
{
	int	c;

	c = ft_contador(n);
	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n *= -1;
		}
		if (n > 9)
		{
			ft_put_nbr(n / 10, fd);
			n = (n % 10);
		}
		if (n < 10 && n >= 0)
		{
			n = n + 48;
			write (fd, &n, 1);
		}
	}
	return (c);
}
