#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int		main(void)
{
	int		pid[3];

	if ((pid[0] = fork()) == -1)
		puts("프로세스 생성 실패!\n\n");
	if (pid[0] != 0)
	{
		waitpid(-1, NULL, 0);
		puts("첫 번째 자식 프로세스!\n");
		pid[1] = fork();
		puts("두 번째 자식 프로세스!\n");
		exit(5);
		pid[2] = fork();
		puts("세 번째 자식 프로세스!\n");
	}
	return (0);
}
