#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024
#define READ 0
#define WRITE 1

int		main(void)
{
	int		fd[2];
	char	buf[BUFFER_SIZE];
	pid_t	pid;

	if (pipe(fd) == -1)
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
		close(fd[WRITE]);
		read(fd[READ], buf, BUFFER_SIZE);
		printf("child's process got message : %s\n", buf);
	}
	else
	{
		close(fd[READ]);
		strcpy(buf, "I'm parent's process");
		write(fd[WRITE], buf, strlen(buf)); 
	}
	exit(0);
	return (0);
}
