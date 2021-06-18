/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmdn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:29 by donpark           #+#    #+#             */
/*   Updated: 2021/06/19 04:09:30 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	heredoc_re_conn_cmd(int **fd, int *i, char **argv, char **env)
{
	redirect_out(argv[(*i) + 1], argv);			// stdout → file2	// i == argc -2 이므로 argc - 1은 i + 1하면됨
	connect_pipe(fd, (*i) - 4, STDIN_FILENO);	// pipe → stdin		// cmd=3이면, argc=7, (*i)=5, pipe: fd[1][2]
	cmd_execve(argv[(*i)], env);
}

void	re_conn_cmd(int **fd, int *i, char **argv, char **env)
{
	redirect_out(argv[(*i) + 1], argv);			// stdout → file2	// i == argc -2 이므로 argc - 1은 i + 1하면됨
	connect_pipe(fd, (*i) - 3, STDIN_FILENO);	// pipe → stdin		// cmd=3이면, argc=6, (*i)=4, pipe: fd[1][2]
	cmd_execve(argv[(*i)], env);
}

void	run_cmdn(int **fd, int *i, char **argv, char **env)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) < 0)
		exit(-1);
	else if (pid == 0)
	{
		if (is_heredoc(argv))
		{
			heredoc_re_conn_cmd(fd, i, argv, env);
			// redirect_out(argv[(*i) + 1], argv);			// stdout → file2	// i == argc -2 이므로 argc - 1은 i + 1하면됨
			// connect_pipe(fd, (*i) - 4, STDIN_FILENO);	// pipe → stdin		// cmd=3이면, argc=7, (*i)=5, pipe: fd[1][2]
			// cmd_execve(argv[(*i)], env);
		}
		else
		{
			re_conn_cmd(fd, i, argv, env);
			// redirect_out(argv[(*i) + 1], argv);			// stdout → file2	// i == argc -2 이므로 argc - 1은 i + 1하면됨
			// connect_pipe(fd, (*i) - 3, STDIN_FILENO);	// pipe → stdin		// cmd=3이면, argc=6, (*i)=4, pipe: fd[1][2]
			// cmd_execve(argv[(*i)], env);
		}
		exit(0);
	}
	else
	{
		if (is_heredoc(argv))
		{
			close_pipe(fd, (*i) - 4);
			clear_temp();
		}
		else
			close_pipe(fd, (*i) - 3);
		waitpid(pid, &status, 0);
	}
}
