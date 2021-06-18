#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFER_SIZE 1024

int		main(void)
{
	int	fd1, fd2;
	char	message[32] = "message fd2\n";
	char	buf[BUFFER_SIZE] = {0};

	fd1 = open("test.txt", O_RDWR|O_CREAT);
	if (fd1 == -1)
	{
		perror("file open error");
		exit(1);
	}
	read(fd1, buf, BUFFER_SIZE);
	printf("f1 content : %s\n", buf);
	
	memset(buf, 0, sizeof(buf));

	fd2 = dup(fd1);
	if (fd2 == -1)
	{
		perror("dup fail");
		exit(1);
	}
	write(fd2, message, strlen(message));
	// write로 추가한 메시지까지 읽지 않고 복사되었을때 상태의 메시지까지 읽게된다.
	read(fd2, buf, BUFFER_SIZE);
	printf("f2 content : %s\n", buf);

	printf("fd1: %d, fd2: %d\n", fd1, fd2);	// 가장 가까운 fd 값에 복제된다.
	close(fd1);
	close(fd2);
	return (0);
}
