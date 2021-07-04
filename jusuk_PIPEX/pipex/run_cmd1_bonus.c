/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:31 by donpark           #+#    #+#             */
/*   Updated: 2021/06/19 04:09:32 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_cmd1(int **fd, int *i, char **argv, char **env)
{
	pid_t	pid;
	int		status;

	if ((pid = fork()) < 0)
		exit(-1);
	else if (pid == 0)
	{
		if (is_heredoc(argv))
		{
			heredoc(argv[2]);
			connect_pipe(fd, (*i) - 3, STDOUT_FILENO);		// stdout → pipe	pipe: fd[0][2]
			cmd_execve(argv[(*i)], env);
		}
		else
		{
			redirect_in(argv[WRITE]);					// file1 → stdin
			connect_pipe(fd, (*i) - 2, STDOUT_FILENO);	// stdout → pipe	pipe: fd[0][2]
			cmd_execve(argv[(*i)], env);
		}
		exit(0);
	}
	else
		waitpid(pid, &status, 0);
}
