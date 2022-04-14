/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarre <clcarrer@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:19:39 by clcarre           #+#    #+#             */
/*   Updated: 2022/04/14 09:23:00 by clcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
No es necesario gestionar el buffer como lo hace el printf original.
Deberá implementar las siguientes conversiones: cspdiuxX %.
Su funcionamiento se contrastará con el printf original.
El uso de libtool está prohibido. 
En cambio, deberás utilizar el comando ar para generar la librería.
Tu archivo libftprintf.a deberá generarse en la raíz de tu repositorio.

Una pequeña y simple descripción de las conversiones que se te piden:
- %c para imprimir un solo carácter.
- %s para imprimir una string (como se define por convención en C).
- %p el puntero void * dado como argumento se imprimirá en hexadecimal.
- %d para imprimir un número decimal (de base 10).
- %i para imprimir un entero en base 10.
- %u para imprimir un número decimal (de base 10) sin signo.
- %x para imprimir un número hexadecimal (de base 16), en minúscula.
- %X para imprimir un número hexadecimal (de base 16), en mayúscula.
- % % para imprimir el signo del porcentaje.
*/
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putunsigned_fd(int n, int fd)
{
	if (n < 0)
		return ;
	else if (n > 9)
	{
		ft_putunsigned_fd(n / 10, fd);
		n = (n % 10);
	}
	if (n < 10 && n >= 0)
	{
		n = n + 48;
		write (fd, &n, 1);
	}
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

void	ft_putnbr_fd(int n, int fd)
{
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
			ft_putnbr_fd(n / 10, fd);
			n = (n % 10);
		}
		if (n < 10 && n >= 0)
		{
			n = n + 48;
			write (fd, &n, 1);
		}
	}
}

void	ft_dec_a_hex(int n, int fd, char *base)
{
	int		i;

	if (n > 16)
	{
		ft_dec_a_hex(n / 16, fd, base);
		n = (n % 16);
	}
	if (n <= 16)
	{
		i = 0;
		while (i < n)
			base[i++];
		write (fd, &base[i], 1);
	}
}

int	ft_printf(char const *str, ...)
{
	va_list			args;
	unsigned int	i;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 's' || str[i + 1] == 'c')
				ft_putstr_fd(va_arg(args, char *), 1);
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')
				ft_putnbr_fd(va_arg(args, int), 1);
			else if (str[i + 1] == 'x')
				ft_dec_a_hex(va_arg(args, int), 1, "0123456789abcdef");
			else if (str[i + 1] == 'X')
				ft_dec_a_hex(va_arg(args, int), 1, "0123456789ABCDEF");
			else if (str[i + 1] == '%')
				write (1, "%%", 1);
			i = i + 2;
		}
		write (1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	printf("Hola la direccción de str es %X\n", 940);
	ft_printf("Hola la direccción de str es %X\n", 940);
	return (0);
}
