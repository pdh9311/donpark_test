#include "pipex.h"

int		main(int argc, char *argv[], char **env)
{
	int		fd[2];
	int		status;
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("pipe() error");
		exit(1);
	}
	// printf("fd[0] : %d, fd[1] : %d\n", fd[0], fd[1]);
	pid = fork();	// fork() return value : child process id
	if (pid == -1)
	{
		perror("fork() error");
		exit(1);
	}
	else if (pid == 0)	// child process
	{
		redirect_in(argv[1]);	// file1
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		run_cmd(argv[2], env);
		exit(0);
	}
	else if (pid > 0)	// parent process
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) == 0)	// 자식 프로세스가 정상적으로 종료되었다면 TRUE를 반환하는 매크로를 사용
			exit(1);
		redirect_out(argv[argc - 1]);	//file2
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		run_cmd(argv[3], env);
		exit(0);
	}

	return (0);
}
