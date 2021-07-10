NAME = mlxTest
SRC = main.c
OBJ = $(SRC:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OS_NAME = $(shell uname -s)

ifeq ($(OS_NAME), Darwin)
	MLX = ./mlx
	LFLAGS = -L$(MLX) -lmlx -framework OpenGL -framework AppKit
else
	MLX = ./minilibx-linux
	LFLAGS = -L$(MLX) -lmlx -L/usr/lib -lXext -lX11 -lm
endif

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

clean :
	rm -rf $(NAME) $(OBJ)

help :
	@echo $(OS_NAME)
	@echo $(MLX)
	@echo $(LINK)
