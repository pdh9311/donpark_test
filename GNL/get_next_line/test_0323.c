#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

#ifndef OPEN_MAX
# define OPEN_MAX 65536
#endif

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;

	if (!(new_str = (char *)malloc(ft_strlen(s) + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}


char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*strjoin;
	int		i;

	if (!s1 && !s2)
		return (0);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else
	{
		if (!(strjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		i = 0;
		while (*s1)
			strjoin[i++] = *(s1++);
		while (*s2)
			strjoin[i++] = *(s2++);
		strjoin[i] = '\0';
	}
	return (strjoin);
}

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

int	split_line(char **backup, char **line, int cut_idx, char *buf)
{
	char	*tmp;
	int		len;

	if (buf)
	{
		free(buf);
		buf = 0;
	}
	(*backup)[cut_idx] = '\0';
	if ((*line = ft_strdup(*backup)) == 0)
		return (-1);
	len = ft_strlen(*backup + cut_idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	tmp = ft_strdup(*backup + cut_idx + 1);
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
		return (-1);
	if (*backup && (cut_idx = is_newline(*backup)) != -1)
		return (split_line(backup, line, cut_idx, buf));
	if (*backup)
	{
		*line = *backup;
		*backup = 0;
	}
	else
		*line = ft_strdup("");
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
		if ((tmp = ft_strjoin(backup[fd], buf)) == 0)
			return (-1);
		if(backup[fd])
		{
			free(backup[fd]);
			backup[fd] = 0;
		}
		backup[fd] = tmp;
		if ((cut_idx = is_newline(backup[fd])) != -1)
			return (split_line(&backup[fd], line, cut_idx, buf));
	}
	return (remains_data(&backup[fd], line, read_size, buf));
}

int	main(void)
{
	int		fd;
	char	*line;
	int		ret;
	int		cnt = 0;

	fd = open("gnltest.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		cnt++;
		printf("(%d) %s\n", cnt, line);
		free(line);
	}
	printf("(%d) %s\n", cnt, line);
	free(line);
	close(fd);
	return (0);
}
