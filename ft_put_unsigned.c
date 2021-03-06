/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarre <clcarrer@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:32:55 by clcarre           #+#    #+#             */
/*   Updated: 2022/04/22 08:19:00 by clcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_contador(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_put_unsigned(unsigned int n, int fd)
{
	int	c;

	c = ft_contador(n);
	if (n > 9)
	{
		ft_put_unsigned(n / 10, fd);
		n = (n % 10);
	}
	if (n < 10)
	{
		n = n + 48;
		write (fd, &n, 1);
	}
	return (c);
}
