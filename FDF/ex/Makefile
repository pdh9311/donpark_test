NAME = fdf

CC = gcc
CFLAGE = -Wall -Werror -Wextra

# -I : 헤더파일 경로
# -L : mlx 라이브러리 경로(mlx 폴더 이름), 기본적으로 /lib, /usr/lib, /usr/local/lib 만을 검색해서 라이브러리를 찾지만 추가적으로 디렉토리를 검색하도록 할때 사용한다.
# -l : 라이브러리파일 이름(앞의 lib 와 뒤의 .a 를 제외한 이름), 정적 라이브러리를 "링크"시키는데 사용된다.

# INC = -I./
# LIB_PATH = -L../mlx
LIB = -lmlx
# MATH_LIB = -lm
FRAMEWORK = -framework OpenGL -framework AppKit

#	$(CC) $(CFLAGE) $(LIB_PATH) $(LIB) $(FRAMEWORK) test.c -o a.out
all:
	$(CC) $(CFLAGE) $(LIB) $(FRAMEWORK) test.c -o a.out
	./a.out

clean:
	rm -rf *.out
