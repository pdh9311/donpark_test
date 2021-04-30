NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)

LIBFT = libft
LIBFT_LIB = libft.a

.PHONY : all clean fclean re

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $? -o $@

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	cp ./$(LIBFT)/$(LIBFT_LIB) ./$(NAME)
	$(AR) $@ $^
# -C dir
# Makefile을 계속 읽지 말고 우선은 dir로 이동하라는 것이다.
# http://doc.kldp.org/KoreanDoc/html/GNU-Make/GNU-Make-5.html
clean :
	rm -f $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

