/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:19:39 by clcarre           #+#    #+#             */
/*   Updated: 2022/04/19 13:46:21 by marvin           ###   ########.fr       */
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
#include "ft_printf.h"

static int	ft_write(va_list args, char const str)
{
	int	c;

	c = 0;
	if (str == 'c')
		c = c + ft_put_c(va_arg(args, int), 1);
	else if (str == 's')
		c = c + ft_put_str(va_arg(args, char *), 1);
	else if (str == 'p')
		c = c + ft_put_ptr(va_arg(args, unsigned long long), 1);
	else if (str == 'd' || str == 'i')
		c = c + ft_put_nbr(va_arg(args, int), 1);
	else if (str == 'u')
		c = c + ft_put_unsigned(va_arg(args, unsigned int), 1);
	else if (str == 'x')
		c = c + ft_dec_a_hex(va_arg(args, unsigned int), 1, "0123456789abcdef");
	else if (str == 'X')
		c = c + ft_dec_a_hex(va_arg(args, unsigned int), 1, "0123456789ABCDEF");
	else if (str == '%')
	{
		write (1, "%%", 1);
		c++;
	}
	return (c);
}

int	ft_printf(char const *str, ...)
{
	va_list			args;
	unsigned int	i;
	unsigned int	c;

	va_start(args, str);
	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			c = c + ft_write(args, str[i + 1]);
			i = i + 2;
		}
		else
		{
			write (1, &str[i++], 1);
			c++;
		}
	}
	va_end(args);
	return (c);
}
/*
int	main(void)
{	
	int	x;
	int	a;
	int	ptr;

	a = printf("ptr es %c\n", '*');
	x = ft_printf("ptr es %c\n", '*');
	printf("%d y %d\n", a, x);
	return (0);
}*/
