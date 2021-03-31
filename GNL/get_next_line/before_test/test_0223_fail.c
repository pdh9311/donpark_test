#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <fcntl.h>

# define BUFFER_SIZE 5
# define OPEN_MAX 65536

int		ft_strlen(const char *s)
{
	int	i;

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

int	split_line(char *backup, char **line, int cut_idx)
{
	char	*temp;
	int		len;
	int		i;
	int		line_len;
	char	*new_backup;

	backup[cut_idx] = '\0';
	line_len = ft_strlen(backup);
	*line = ft_strdup(backup);
	new_backup = backup + cut_idx + 1;
	len = ft_strlen(new_backup);
	if (len == 0)
	{
		free(backup);
		backup = 0;
		return (1);
	}
	temp = ft_strdup(new_backup);
	printf("backup		: %p\n", backup);
	printf("new_backup	: %p\t%s\n", temp, temp);
	free(backup);
	backup = temp;
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			read_size;
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;
	int			cut_idx;

	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		printf("first_backup	: %p\t%s\n", backup, backup);
		backup = ft_strjoin(backup, buf);
		printf("gnl_ backup	: %p\t%s\n", backup, backup);
		if ((cut_idx = is_newline(backup)) >= 0)
			return (split_line(backup, line, cut_idx));
	}
	if (read_size < 0)
		return (-1);
	if (backup)
	{
		*line = backup;
		backup = "";
		return (0);
	}
}

int	main(void)
{
	int		fd;
	char	*line;
	int		ret;

	fd = open("gnltest.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("\tline: %s\n\n", line);
		free(line);
	}
	printf("\tline: %s\n\n", line);
	free(line);
	return (0);
}
