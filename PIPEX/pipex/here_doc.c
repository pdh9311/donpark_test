/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 04:09:49 by donpark           #+#    #+#             */
/*   Updated: 2021/06/19 04:26:29 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		is_heredoc(char **argv)
{
	if (ft_strcmp(argv[1], "here_doc") == 0)
		return (1);
	return (0);
}

void	clear_temp(void)
{
	char	**argv;

	if (!(argv = (char **)malloc(sizeof(char *) * 3)))
	{
		perror("malloc() error");
		exit(-1);
	}
	argv[0] = "-f";
	argv[1] = "./temp";
	argv[2] = NULL;
	execve("/bin/rm", (char *const *)argv, NULL);
}

void	heredoc(char *limiter)
{
	int		fd;
	char	*buf;

	buf = NULL;
	fd = open("./temp", O_CREAT | O_RDWR | O_TRUNC, 0664);
	if (fd < 0)
	{
		perror("open() error");
		exit(-1);
	}
	write(1, "heredoc> ", 9);
	while (get_next_line(STDIN_FILENO, &buf) != 0)
	{
		if (ft_strcmp(buf, limiter) == 0)
			break ;
		write(1, "heredoc> ", 9);
		write(fd, buf, ft_strlen(buf));
		write(fd, "\n", 1);
	}
	close(fd);
	redirect_in("./temp");
}
