#include <stdio.h>		// perror
#include <unistd.h>		// dup, dup2, fork, getpid, wait, waitpid, execve, pipe
#include <fcntl.h>		// open
#include <sys/wait.h>	// waitpid's option
#include <stdlib.h>		// exit
#include <string.h>		// strerror
#include "./libft/libft.h"

# define FILE_1 argv[1]
# define FILE_2 argv[4]
# define CMD_1 argv[2]
# define CMD_2 argv[3]

typedef struct	s_cmd
{
	const char	*cmd[5];
	char *const	*argv;
	char *const *envp;
}				t_cmd;

int		redirect_in(const char *file);
int		redirect_out(const char *file);
void	connect_pipe(int pipefd[2], int io);
void	cmd_init(const char *cmd, t_cmd *cmd_info);
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

void	connect_pipe(int pipefd[2], int io)
{
	dup2(pipefd[2], io);
	close(pipefd[0]);
	close(pipefd[1]);
}

void	cmd_init(const char *cmd, t_cmd *cmd_info)
{
	char	**splited_cmd;
	
	splited_cmd = ft_split(cmd, ' ');
	cmd_info->cmd = ft_strjoin("/bin/", splited_cmd[0]);
	cmd_info->argv = (char *const *)splited_cmd;
	cmd_info->envp = NULL;
}

#if 1 
int		main(void)
{
	int		pipefd[2];
	pid_t	pid;
	t_cmd	cmd_info;

	pipe(pipefd);
	pid = fork();
	if (pid > 0)
	{
		redirect_out(FILE_2);
		connect_pipe(pipefd, STDIN_FIENO);
		cmd_init(CMD_2, &cmd);
		if (execve(cmd_info.cmd, cmd_info.argv, cmd_info.envp) == -1)
			perror(cmd_info.cmd);
	}
	else if (pid == 0)
	{
		redirect_in(FILE_1);
		connect_pipe(pipefd, STDOUT_FILENO);
		if (execve(cmd_info.cmd, cmd_info.argv, cmd_info.envp) == -1)
			perror(cmd_info.cmd);
	}
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

