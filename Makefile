# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clcarre <clcarrer@student.42madrid.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 08:22:53 by clcarre           #+#    #+#              #
#    Updated: 2022/04/14 10:03:17 by clcarre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  	= libftprintf.a 
LIB 	= ar -rcs

SRC		= ft_printf.c

OBJS 	= $(SRC:.c=.o)

CFLAGS 	= -Wall -Wextra -Werror

$(NAME) : $(OBJS)
	$(LIB) $(NAME) $(OBJS)

.c.o :
	gcc $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

clean : 
	rm -f $(OBJS) $(OBJS_B)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re