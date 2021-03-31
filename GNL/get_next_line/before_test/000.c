#include <stdio.h>	// printf
#include "0_get_next_line.h"

int		is_newline(char *backup)
{
	int				i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		split_line(char **backup, char **line, int cut_idx)
{
	char			*temp;
	int				len;
	(*backup)[cut_idx] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + cut_idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	temp = ft_strdup(*backup + cut_idx + 1);
	// printf("backup		: %p\n", *backup);
	// printf("new_backup	: %p\n", temp);
	free(*backup);
	*backup = temp;
	return (1);
}

int		return_all(char **backup, char **line, int read_size)
{
	int				cut_idx;

	if (read_size < 0)
		return (-1);
	if (*backup && (cut_idx = is_newline(*backup)) >= 0)
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

int		get_next_line(int fd, char **line)
{
	static char		*backup[65536];
	char			buf[BUFFER_SIZE + 1];
	int				read_size;
	int				cut_idx;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buf);
		// printf("gnl_ backup	: %p\n", backup[fd]);
		if ((cut_idx = is_newline(backup[fd])) >= 0)
			return (split_line(&backup[fd], line, cut_idx));
	}
	return (return_all(&backup[fd], line, read_size));
}

int main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open("gnltest.txt", O_RDWR);
	// if (fd < 0)
	// {
	// 	printf("failed open file\n");
	// 	return (-1);
	// }
	// printf("successed open file | fd: %d\n", fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n\n", line);
		free(line);
	}
	printf("%s\n\n", line);
	free(line);

	return (0);
}
