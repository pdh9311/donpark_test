/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:19:48 by seunoh            #+#    #+#             */
/*   Updated: 2021/04/07 14:19:48 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_memfree(void **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = 0;
		return (1);
	}
	return (0);
}

int		cut_newline(char **saver, char **line, char *cut_ptr, char *buf)
{
	char	*tmp;

	if (buf)
		ft_memfree((void**)&buf);
	(*saver)[cut_ptr - *saver] = 0;
	if (!(*line = ft_strdup(*saver)))
	{
		(*saver)[cut_ptr - *saver] = '\n';
		ft_memfree((void**)saver);
		return (-1);
	}
	(*saver)[cut_ptr - *saver] = '\n';
	if (!(tmp = ft_strdup(cut_ptr + 1)))
	{
		ft_memfree((void**)saver);
		return (-1);
	}
	if (*saver)
		ft_memfree((void**)saver);
	*saver = tmp;
	return (1);
}

int		remain_saver(char **saver, char **line, char *buf, int byte)
{
	char	*cut_ptr;

	if (buf)
		ft_memfree((void**)&buf);
	if (byte < 0)
	{
		if (*saver)
			ft_memfree((void**)saver);
		return (-1);
	}
	if (!(*saver))
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	if ((cut_ptr = ft_strchr(*saver, '\n')))
		return (cut_newline(saver, line, cut_ptr, buf));
	*line = *saver;
	*saver = 0;
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			byte;
	static char	*saver[OPEN_MAX];
	char		*cut_ptr;
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte] = 0;
		if (!(tmp = ft_strjoin(saver[fd], buf)))
			return (-1);
		if (saver[fd])
			ft_memfree((void**)&saver[fd]);
		saver[fd] = tmp;
		if ((cut_ptr = ft_strchr(saver[fd], '\n')))
			return (cut_newline(&saver[fd], line, cut_ptr, buf));
	}
	return (remain_saver(&saver[fd], line, buf, byte));
}
