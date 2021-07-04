# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 04:09:45 by donpark           #+#    #+#              #
#    Updated: 2021/06/19 04:09:45 by donpark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./

SRCS_M = main.c \
		pipe.c \
		redirect.c \
		run_only_cmd1.c \
		run_cmd1.c \
		run_cmdn.c \
		run_cmd_mid.c \
		cmd_execve.c \
		here_doc.c \
		util.c

SRCS_B = main_bonus.c \
		pipe_bonus.c \
		redirect_bonus.c \
		run_only_cmd1_bonus.c \
		run_cmd1_bonus.c \
		run_cmdn_bonus.c \
		run_cmd_mid_bonus.c \
		cmd_execve_bonus.c \
		here_doc_bonus.c \
		util_bonus.c

OBJS_M = $(SRCS_M:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

LIBFT = libft
LIBFT_LIB = libft.a

ifdef WITH_BONUS
	SRCS = $(SRCS_B)
	OBJS = $(OBJS_B)
else
	SRCS = $(SRCS_M)
	OBJS = $(OBJS_M)
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
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re : fclean all
