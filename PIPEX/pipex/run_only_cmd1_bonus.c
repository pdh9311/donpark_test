/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_only_cmd1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:08:32 by donpark           #+#    #+#             */
/*   Updated: 2021/06/19 04:08:34 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	run_only_cmd1(char **argv, char **env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0 && is_heredoc(argv))
	{
		heredoc(argv[2]);
		redirect_out(argv[4], argv);
		cmd_execve(argv[3], env);
	}
	if (is_heredoc(argv))
	{
		waitpid(pid, &status, 0);
		clear_temp();
	}
	else
	{
		redirect_in(argv[1]);
		redirect_out(argv[3], argv);
		cmd_execve(argv[2], env);
	}
	exit(0);
}
