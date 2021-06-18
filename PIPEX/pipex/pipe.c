/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:43 by donpark           #+#    #+#             */
/*   Updated: 2021/06/19 04:28:43 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_pipe(int **fd, int cmd_cnt, int pipe_cnt)
{
	int		i;

	i = 0;
	while ((i < pipe_cnt) && (cmd_cnt > 1))	// cmd3까지 있다면, argc=6, cmd의 개수=3, pipe의 개수=2
	{
		if (pipe(fd[i]) == -1)
		{
			perror("pipe() error");
			exit(-1);
		}
		i++;
	}
}

void	connect_pipe(int **fd, int row, int io)
{
	dup2(fd[row][io], io);
	close(fd[row][READ]);
	close(fd[row][WRITE]);
}

void	close_pipe(int **fd, int row)
{
	close(fd[row][READ]);
	close(fd[row][WRITE]);
}
