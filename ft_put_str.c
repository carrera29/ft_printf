/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarre <clcarrer@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 08:32:41 by clcarre           #+#    #+#             */
/*   Updated: 2022/04/22 14:19:58 by clcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (write (1, "(null)", 6));
	while (s[i])
		write(fd, &s[i++], 1);
	return (i);
}
/*
int	main(void)
{
	printf("%s\n", NULL);
	printf("%s\n", ft_put_str(NULL, 1));
	return (0);
}*/