/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 03:26:41 by donpark           #+#    #+#             */
/*   Updated: 2021/06/18 17:15:46 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_newline(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	split_line(char **backup, char **line, int cut_idx, char *buf)
{
	char	*tmp;
	int		len;

	if (buf)
		free(buf);
	(*backup)[cut_idx] = '\0';
	if (!(*line = ft_strdup(*backup)))
		return (-1);
	len = ft_strlen(*backup + cut_idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	if (!(tmp = ft_strdup(*backup + cut_idx + 1)))
		return (-1);
	if (*backup)
		free(*backup);
	*backup = tmp;
	return (1);
}

int	remains_data(char **backup, char **line, int read_size, char *buf)
{
	int	cut_idx;

	if (buf)
	{
		free(buf);
		buf = 0;
	}
	if (read_size < 0)
	{
		free(*backup);
		return (-1);
	}
	if (*backup && (cut_idx = is_newline(*backup)) != -1)
		return (split_line(backup, line, cut_idx, buf));
	if (*backup)
	{
		*line = *backup;
		*backup = 0;
	}
	else
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			read_size;
	char		*buf;
	static char	*backup[OPEN_MAX + 1];
	int			cut_idx;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (!(tmp = ft_strjoin(backup[fd], buf)))
			return (-1);
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = tmp;
		if ((cut_idx = is_newline(backup[fd])) != -1)
			return (split_line(&backup[fd], line, cut_idx, buf));
	}
	return (remains_data(&backup[fd], line, read_size, buf));
}
