#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>

# define BUFFER_SIZE 10
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

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		while (src[i] && (i + 1) < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	if (d_len + 1 > dstsize)
		return (s_len + dstsize);
	while (src[i] && (d_len + i + 1) < dstsize)
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (s_len + d_len);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	len;

	len = ft_strlen(s);
	if (!(new_str = (char *)malloc(len + 1)))
		return (0);
	ft_strlcpy(new_str, s, len + 1);
	return (new_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len  = ft_strlen(s1) + ft_strlen(s2);
	if (!(strjoin = (char *)malloc(len + 1)))
		return (0);
	ft_strlcpy(strjoin, s1, len + 1);
	ft_strlcat(strjoin, s2, len + 1);
	return (strjoin);
}

int	is_newline(char *backup)
{
	int	i;

	// printf("3test\n");
	i = 0;
	while (backup[i])
	{
	// printf("5test\n");
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

char	*set_backup(char *backup, char *buf)
{
	char *tmp;

	if (!backup)
		tmp = ft_strdup(buf);
	else
		tmp = ft_strjoin(backup, buf);
	return (tmp);
}

int	get_next_line(int fd, char **line)
{
	g_cnt++;
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
		tmp = set_backup(backup, buf);
		free(buf);
		if (backup)
			free(backup);
		backup = tmp;
		if ((cut_idx = is_newline(backup)) != -1)
			return (split_line(&backup, line, cut_idx));
	}
	free(buf);
	return (remains_data(&backup, line, read_size));
}

int	main(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("gnltest.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("(%d)\tline : %s\n\n",g_cnt, line);
		free(line);
	}
	printf("(%d)\tline : %s\n\n",g_cnt, line);
	free(line);
	return (0);
}


