/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmdn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:29 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 18:30:59 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_heredoc_n(int **fd, int *i, char **argv, char **env)
{
	redirect_out(argv[(*i) + 1], argv);
	connect_pipe(fd, (*i) - 4, STDIN_FILENO);
	cmd_execve(argv[(*i)], env);
}

void	child_n(int **fd, int *i, char **argv, char **env)
{
	redirect_out(argv[(*i) + 1], argv);
	connect_pipe(fd, (*i) - 3, STDIN_FILENO);
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
			child_heredoc_n(fd, i, argv, env);
		else
			child_n(fd, i, argv, env);
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
