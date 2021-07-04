/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:47 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 19:14:50 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_fd(int ***fd, int pipe_cnt)
{
	int		i;

	if (!((*fd) = (int **)malloc(sizeof(int *) * pipe_cnt)))
	{
		perror("malloc() error");
		exit(-1);
	}
	i = 0;
	while (i < pipe_cnt)
	{
		if (!((*fd)[i++] = (int *)malloc(sizeof(int) * 2)))
		{
			perror("malloc() error");
			exit(-1);
		}
	}
}

void	free_fd(int ***fd, int pipe_cnt)
{
	int		i;

	i = 0;
	while (i < pipe_cnt)
		free((*fd)[i++]);
	free(*fd);
}

void	cmd_pipe_cnt(int argc, char **argv, int *cmd_cnt, int *pipe_cnt)
{
	if (is_heredoc(argv))
	{
		(*cmd_cnt) = argc - 4;
		(*pipe_cnt) = argc - 5;
	}
	else
	{
		(*cmd_cnt) = argc - 3;
		(*pipe_cnt) = argc - 4;
	}
}

int		main(int argc, char *argv[], char **env)
{
	int		i;
	int		**fd;
	int		cmd_cnt;
	int		pipe_cnt;

	cmd_pipe_cnt(argc, argv, &cmd_cnt, &pipe_cnt);
	create_fd(&fd, pipe_cnt);
	if (argc < 4)
		return (0);
	create_pipe(fd, cmd_cnt, pipe_cnt);
	if (cmd_cnt == 1)
		run_only_cmd1(argv, env);
	i = argc - cmd_cnt - 1;
	while (i < argc - 1)
	{
		if (i == (argc - cmd_cnt - 1))
			run_cmd1(fd, &i, argv, env);
		else if (i == argc - 2)
			run_cmdn(fd, &i, argv, env);
		else
			run_cmd_mid(fd, &i, argv, env);
		i++;
	}
	free_fd(&fd, pipe_cnt);
	return (0);
}
