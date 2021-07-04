/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:43 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 19:00:08 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	create_pipe(int **fd, int cmd_cnt, int pipe_cnt)
{
	int		i;

	i = 0;
	while ((i < pipe_cnt) && (cmd_cnt > 1))
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
