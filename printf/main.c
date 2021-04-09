 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:17:50 by seunoh            #+#    #+#             */
/*   Updated: 2021/03/03 18:17:50 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>


void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int		main(void)
{
	char	*f_path1 = "test1.txt";
	char	*line;
	int		fd;
	int		ret;
	int		i;

	if ((fd = open(f_path1, O_RDONLY)) == -1)
	{
		ft_putstr("File1 Not Open\n");
		return (0);
	}
	ft_putstr("Open Success\n");
	i = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ft_putstr(line);
		free(line);
		line = NULL;
		ft_putstr("\n");
		i++;
		// if (i == 6)
			// close(fd);
	}
	if (ret < 0)
	{
		ft_putstr("Read error\n");
		if (line)
			free(line);
	}
	else if (ret == 0)
		ft_putstr("read end\n");
	close(fd);
	return (0);
}
