#include "0_get_next_line.h"

int	is_newline(char *backup)
{
	int	i;

	i = 0;
	while (backup[i])
	{
		if(backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	split_line(char **backup, char **line, int cut_idx)
{
	char	*temp;
	int		len;

	(*backup)[cut_idx] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + cut_idx  +1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + cut_idx + 1);
	free(*backup);
	*backup = temp;
	return (1);
}

int	remains_data(char **backup, char **line, int read_size)
{
	int	cut_idx;

	if (read_size < 0)
		return (-1);
	if (*backup && (cut_idx = is_newline(*backup)) != -1)
		return (split_line(backup, line, cut_idx));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			read_size;
	char		*buf;
	static char	*backup;
	int			cut_idx;

	if (BUFFER_SIZE == 0 || fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	*line = 0;
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup = ft_strjoin(backup, buf);
		if ((cut_idx = is_newline(backup)) != -1)
			return (split_line(&backup, line, cut_idx));
	}
	return (remains_data(&backup, line, read_size));
}
