#include <stdio.h>		// perror
#include <unistd.h>		// dup, dup2, fork, getpid, wait, waitpid, execve, pipe
#include <fcntl.h>		// open
#include <sys/wait.h>	// waitpid's option
#include <stdlib.h>		// exit
#include <string.h>		// strerror

///////////////////////////////////////////////////////
// file1 ------> cmd1 -----------> cmd2 -----> file2 //
//             ^    ^            ^    ^				 //
//        (stdin)  (stdout) (stdin)  (stdout)		 //
///////////////////////////////////////////////////////        

// file1 to stdin	:	< file1
int		redirect_in(const char *file)
{
	int		fd;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDIN_FILENO);		// stdin이 fd를 참조하도록 만듬
	close(fd);
	return (0);
}

// stdout to file2	:	> file2
int		redirect_out(const char *file)
{
	int		fd;

	fd = open(file, O_RDWR | O_CREAT, 00644);
	if (fd < 0)
	{
		perror(file);
		return (-1);
	}
	dup2(fd, STDOUT_FILENO);		// stdout이 fd를 참조하도록 만듬
	close(fd);
	return (0);
}

#if 0
// redirection test
int		main(int argc, char const *argv[])
{
	if (argc == 3)
	{
		redirect_in(argv[1]);
//		execve("/bin/cat", 0, 0);
		redirect_out(argv[2]);
		printf("stdout test\n");
	}
	else
		printf("argument is wrong");
	return (0);
}
#endif

#if 0
// fork test
int		main(void)
{
	pid_t	pid;

	pid = fork();
	if (pid > 0)
	{
		printf("parent PID : %d\n" ,getpid());
		printf("PID form fork() to the parent: %d\n", pid);
	}
	else if (pid == 0)
	{
		printf("child PID : %d\n" ,getpid());
		printf("PID form fork() to the child: %d\n", pid);
	}
	return (0);
}
#endif
