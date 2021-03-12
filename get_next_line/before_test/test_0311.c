#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>

# define BUFFER_SIZE 30
# define OPEN_MAX 65536

int	g_cnt;

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
	char	*temp;
	int		len;

	if(buf)
		free(buf);
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
	free(*backup);
	*backup = temp;
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
	char		*tmp;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{

		buf[read_size] = '\0';
		tmp = ft_strjoin(backup, buf);
		if(backup)
		{
			free(backup);
			backup = 0;
		}
		backup = tmp;
		if ((cut_idx = is_newline(backup)) != -1)	// backup에 개행이 있으면
		{
			printf("buf : %p\n", buf);
			return (split_line(&backup, line, cut_idx, buf));
		}
	}
	return (remains_data(&backup, line, read_size, buf));
}

int	main(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("gnltest.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("(%d)\tline : %s\n",g_cnt, line);
		free(line);
	}
	// printf("ret: %d\n", ret);
	printf("(%d)\tline : %s\n",g_cnt, line);
	free(line);
	return (0);
}
