#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024
#define READ 0
#define WRITE 1

int		main(void)
{
	int		fdA[2], fdB[2];
	pid_t	pid;
	char	buf[BUFFER_SIZE] = {0};

	if (pipe(fdA) == -1 || pipe(fdB) == -1)
	{
		perror("pipe() error");
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork() error");
		exit(1);
	}
	else if (pid == 0)
	{
		close(fdA[WRITE]);
		close(fdB[READ]);

		strcpy(buf, "hello parent_process, i am child process");
		write(fdB[WRITE], buf, strlen(buf));

		memset(buf, 0, sizeof(buf));

		read(fdA[READ], buf, BUFFER_SIZE);
		printf("child_process got message: %s\n", buf);
	}
	else
	{
		close(fdA[READ]);
		close(fdB[WRITE]);

		strcpy(buf, "hi child_process, i am parent process");
		write(fdA[WRITE], buf, strlen(buf));
		
		memset(buf, 0, sizeof(buf));

		read(fdB[READ], buf, BUFFER_SIZE);
		printf("parent_process got message: %s\n", buf);
	}

	exit(0);
	return (0);
}
