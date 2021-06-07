#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main(void)
{
	int	pid, child_pid;
	int	status;

	pid = fork();
	if (pid != 0)
	{
		child_pid = wait(&status);
		printf("자식[pid : %d] 종료된 기록 : %x\n", child_pid, status);
	}
	else
	{
		printf("자식프로세스 출력!!\n");
		exit(5);
	}	
	return (0);
}
