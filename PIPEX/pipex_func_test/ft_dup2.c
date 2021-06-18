#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

int		main(void)
{
	int		fd1, ret;
	char	message[32] = "fd1 -> STDERR\n";

	// image 1
	fd1 = open("test.txt", O_RDWR|O_CREAT);
	if (fd1 == -1)
	{
		perror("file open error");
		exit(1);
	}
	
	// image 2
	ret = dup2(fd1, STDOUT_FILENO);		// 표준출력이면서 test.txt 파일인 상태??...
	printf("fd1 :%d, ret:%d\n", fd1, ret);	// printf는 표준출력이므로 test.txt 파일에 기록된다.

	// image 3
	ret=dup2(STDERR_FILENO, fd1);	// fd1을 표준에러로 redirect한다.
	write(fd1, message, strlen(message));	// message가 표준에러로 출력된다.
	printf("printf를 썼지만 파일에 기록됨 \n");	// printf는 표준출력이므로 test.txt 파일에 기록된다.


	close(fd1);
	return (0);
}
