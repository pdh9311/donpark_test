# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 13:28:09 by donpark           #+#    #+#              #
#    Updated: 2021/05/06 13:28:12 by donpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS = ft_printf.c 	check_info.c \
	apply_to_char.c apply_to_int.c \
	print_int.c print_char.c \
   	utils1.c utils2.c
OBJS = $(SRCS:.c=.o)


.PHONY : all clean fclean re

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $? -o $@

$(NAME) : $(OBJS)
	$(AR) $@ $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

