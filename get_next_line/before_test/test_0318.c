#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
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

int	split_line(char **backup, char **line, int cut_idx)
{
	char	*tmp;
	int		len;

	(*backup)[cut_idx] = '\0';
	*line = ft_strdup(*backup);
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

int	remains_data(char **backup, char **line, int read_size)
{
	int	cut_idx;

	if (read_size < 0)
		return (-1);
	if (*backup && (cut_idx = is_newline(*backup)) != -1)
		return (split_line(backup, line, cut_idx));
	if (*backup)
	{
		printf("not end newline\n");
		*line = *backup;
		*backup = 0;
	}
	else
	{
		printf("end newline\n");
		*line = ft_strdup("");
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	int			read_size;
	char		*buf;
	static char	*backup[OPEN_MAX];
	char		*tmp;
	int			cut_idx;
	
	if (BUFFER_SIZE <= 0 || fd < 0 || fd > OPEN_MAX || !line)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		// printf("backup[fd]: %s\t%p\n", backup[fd], backup[fd]);
		tmp = ft_strjoin(backup[fd], buf);
		if(backup[fd])
			free(backup[fd]);
		backup[fd] = tmp;
		if ((cut_idx = is_newline(backup[fd])) != -1)
		{
			free(buf);
			return (split_line(&backup[fd], line, cut_idx));
		}
	}
	free(buf);
	return (remains_data(&backup[fd], line, read_size));
}

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line;
	int		ret;
	int		ret_bonus;
	int		g_cnt = 0;

	fd1 = open("gnltest.txt", O_RDONLY);
	fd2 = open("gnlbonustest.txt", O_RDONLY);
	while ((ret = get_next_line(fd1, &line)) > 0)
	{
		g_cnt++;
		printf("(%d) %s\n", g_cnt, line);
		free(line);
	}
	g_cnt++;
	if (ret == 0)
	{
		printf("(%d) %s\n", g_cnt, line);
		free(line);
	}

	// while ((ret_bonus = get_next_line(fd2, &line)) > 0)
	// {
	// 	printf("%s\n", line);
	// 	free(line);
	// }
	// if (ret_bonus == 0)
	// {
	// 	printf("%s\n",line);
	// 	free(line);
	// }
	return (0);
}
