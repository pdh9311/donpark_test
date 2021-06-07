#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		main(void)
{
    pid_t pid;

    if ((pid=vfork()) == -1)
       perror("fork failed");
    if (pid != 0)
       printf("PID is %d, child process pid is %d\n", getpid(), pid);
    else
       printf("PID is %d, parent process pid is %d\n", getpid(), getppid());
	exit(0);	// stdlib.h
	return (0);
}
