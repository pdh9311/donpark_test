#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#	define BUFFER_SIZE 1
#endif

#ifndef OPEN_MAX
#	define OPEN_MAX 65535
#endif

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		i;

	if (!(new_str = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1)))
		return (0);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
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
		if (!(strjoin = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
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

int		is_newline(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		split_line(char **backup, char **line, int cut_idx)
{

	char	*tmp;
	int		len;

	(*backup)[cut_idx] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + cut_idx + 1);
	if (len == 0)	// backup에 딱 \n까지만 있었던 경우
	{
		free(*backup);
		/* free 후에는 backup은 허상포인트가 되는데 
		이는 값을 가리키고는 있지만 사용할수없는 메모리이기 때문에
		알 수 없는 값이 들어가게되므로 
		다음 gnl 호출시 backup에는 아무런값이 없도록 지정해주기 위해서
		NULL값 0으로 초기화 해주었습니다. */
		*backup = 0;
		return (1);
	}
	tmp = ft_strdup(*backup + cut_idx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int		remains_data(char **backup, char **line, int read_size)
{
	int	cut_idx;

	if (read_size < 0)
		return (-1);
	if (*backup && (cut_idx = is_newline(*backup)) > 0)
		return (split_line(backup, line, cut_idx));
	if (*backup)	// 파일의 마지막에 \n 이 없는 경우
	{
		*line = *backup;
		free(*backup);
	}
	else
		*line = ft_strdup("");
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			read_size;
	char		*buf;
	static char	*backup[OPEN_MAX];
	char		*tmp;
	int			cut_idx;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE = 0)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		tmp = ft_strjoin(backup[fd], buf);
		if (backup[fd])
			free(backup[fd]);
		backup[fd] = tmp;
		if ((cut_idx = is_newline(backup[fd])) != -1)
		{
			free(buf);
			return (split_line(&backup[fd], line, cut_idx, buf));
		}
	}
	free(buf);
	return (remains_data(&backup[fd], line, read_size));
}

int		main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open("gnltext.txt", O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	return (0);
}
