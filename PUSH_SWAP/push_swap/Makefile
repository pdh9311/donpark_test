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

ifdef WITH_BONUS
	SRCS = $(SRCS_B)
	OBJS = $(OBJS_B)
	NAME = $(CHECKER)
else
	SRCS = $(SRCS_M)
	OBJS = $(OBJS_M)
	NAME = $(PUSH_SWAP)
endif

.PHONY : all clean fclean re bonus

all : $(NAME)

$(OBSJ) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ -c $?

$(NAME) : $(OBJS)
	make all -C $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ ./$(LIBFT)/$(LIBFT_LIB)

bonus :
	make WITH_BONUS=1 all

clean :
	rm -f $(OBJS_M) $(OBJS_B)
	make clean -C $(LIBFT)

fclean : clean
	rm -f $(PUSH_SWAP) $(CHECKER)
	make fclean -C $(LIBFT)

re : fclean all
