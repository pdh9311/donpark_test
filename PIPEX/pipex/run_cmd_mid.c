/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:34 by donpark           #+#    #+#             */
/*   Updated: 2021/06/19 05:08:03 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_heredoc_mid(int **fd, int *i, char **argv, char **env)
{
	connect_pipe(fd, (*i) - 4, STDIN_FILENO);	// pipe → stdin		// cmd=3이면, argc=6, (*i)=3, pipe: fd[0][2]
	connect_pipe(fd, (*i) - 3, STDOUT_FILENO);	// stdout → pipe	// cmd=3이면, argc=6, (*i)=3, pipe: fd[1][2]
	cmd_execve(argv[(*i)], env);
}

void	child_mid(int **fd, int *i, char **argv, char **env)
{
	connect_pipe(fd, (*i) - 3, STDIN_FILENO);	// pipe → stdin		// cmd=3이면, argc=6, (*i)=3, pipe: fd[0][2]
	connect_pipe(fd, (*i) - 2, STDOUT_FILENO);	// stdout → pipe	// cmd=3이면, argc=6, (*i)=3, pipe: fd[1][2]
	cmd_execve(argv[(*i)], env);
}

void	run_cmd_mid(int **fd, int *i, char **argv, char **env)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) < 0)
		exit(-1);
	else if (pid == 0)
	{
		if (is_heredoc(argv))
			child_heredoc_mid(fd, i, argv, env);
		else
			child_mid(fd, i, argv, env);
		exit(0);
	}
	else if (pid > 0)
	{
		if (is_heredoc(argv))
			close_pipe(fd, (*i) - 4);
		else
			close_pipe(fd, (*i) - 3);
		waitpid(pid, &status, 0);
	}
}
