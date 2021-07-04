#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	int		argc = 10;
	pid_t	pid;
	int		i;

	i = 0;
	while (i < argc)
	{
		pid = vfork();
		i++;
	}
	printf("ParentPID is %d, MyPID is %d, ChildPID is %d\n", getppid(), getpid(), pid);
	exit(0);
	return (0);
}
