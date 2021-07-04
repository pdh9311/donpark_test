PUSH_SWAP = push_swap
CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./

SRCS_M = push_swap.c push_swap_sub.c \
		list_func.c list_func_sub.c \
		push_swap_func.c find_pivot.c \
		sort.c sort_sub.c \
		sort_23_ab.c \
		sort_23_ba.c sort_23_ba_sub.c \
		print_instructions.c utils.c

SRCS_B = checker.c checker_sub.c push_swap_sub.c \
		list_func.c list_func_sub.c utils.c

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

LIBFT = libft
LIBFT_LIB = libft.a

.PHONY : all clean fclean re

all : $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP) : $(OBJS_M)
	make all -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ ./$(LIBFT)/$(LIBFT_LIB)

$(CHECKER) : $(OBJS_B)
	$(CC) $(CFLAGS) -o $@ $^ ./$(LIBFT)/$(LIBFT_LIB)

clean :
	rm -f $(OBJS_M) $(OBJS_B)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(PUSH_SWAP) $(CHECKER)
	make fclean -C $(LIBFT)

re : fclean all
