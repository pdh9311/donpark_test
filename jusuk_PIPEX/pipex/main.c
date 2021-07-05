/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:47 by donpark           #+#    #+#             */
/*   Updated: 2021/07/05 12:01:54 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_fd(int ***fd, int pipe_cnt)	// fd[0][2], fd[1][2], fd[2][2] ...
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

/**
 * ./pipex file1 cmd1 file2
 * (argc = 4), (cmd_cnt = argc -3), (pipe_cnt = cmd_cnt -1 = zero)
 *
 * ./pipex file1 cmd1 cmd2 file2
 * (argc = 5), (cmd_cnt = argc -3), (pipe_cnt = cmd_cnt -1 = argc -4)
 *
 * ./pipex here_doc LIMITER cmd1 file2
 * (argc = 5), (cmd_cnt = argc -4), (pipe_cnt = cmd_cnt -1 = zero)
 *
 * ./pipex here_doc LIMITER cmd1 cmd2 file2
 * (argc = 6), (cmd_cnt = argc -4), (pipe_cnt = cmd_cnt -1 = argc -5)
 */
/**	cmd의 시작 index 위치
 * here_doc인 경우 ./pipex here_doc LIMITER cmd1 cmd2 file2
 * cmd_idx = 3 = argc - 3 ********** argc = 6
 * 그 외의 경우 ./pipex file1 cmd1 cmd2 file2
 * cmd_idx = 2 = argc - 3 ************ argc = 5
 */

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
	if (cmd_cnt == 1)				// cmd1 밖에 없을 경우
		run_only_cmd1(argv, env);
	i = argc - cmd_cnt - 1;			// cmd1의 시작 위치
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

