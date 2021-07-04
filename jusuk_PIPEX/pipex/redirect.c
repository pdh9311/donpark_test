/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:36 by donpark           #+#    #+#             */
/*   Updated: 2021/06/19 04:29:17 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	redirect_in(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	redirect_out(char *file, char **argv)
{
	int		fd;

	if (is_heredoc(argv))
	{
		fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0664);
	}
	else
		fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0664);
	if (fd < 0)
	{
		perror(file);
		exit(-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
