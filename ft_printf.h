/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clcarre <clcarrer@student.42madrid.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:35:13 by clcarre           #+#    #+#             */
/*   Updated: 2022/04/18 16:36:33 by clcarre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *str, ...);
int	ft_dec_a_hex(unsigned int n, int fd, char *base);
int	ft_put_nbr(int n, int fd);
int	ft_put_ptr(unsigned long long ptr, int fd);
int	ft_put_str(char *s, int fd);
int	ft_put_c(int c, int fd);
int	ft_put_unsigned(unsigned int n, int fd);
#endif