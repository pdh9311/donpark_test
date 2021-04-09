//include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 3000

size_t	ft_strlen(const char *str)
{
	size_t  len;
	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*ft_strchr(const char *s, int c)
{
	const char  *str;

	str = s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strdup(const char *s)
{
	int		tmp;
	char	*str;

	tmp = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * (tmp + 1))))
		return (NULL);
	tmp = 0;
	while (*s)
		str[tmp++] = *s++;
	str[tmp] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t  i;

	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	ft_memfree((void**)&s1);
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

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
​
int		cut_newline(char **saver, char **line, char *cut_ptr)
{
	char	*tmp;
​
	(*saver)[cut_ptr - *saver] = 0;
	if (!(*line = ft_strdup(*saver)))
	{
		(*saver)[cut_ptr - *saver] = '\n';
		ft_memfree((void**)&saver);
		return (-1);
	}
	(*saver)[cut_ptr - *saver] = '\n';
	if (!(tmp = ft_strdup(cut_ptr + 1)))
	{
		ft_memfree((void**)&saver);
		return (-1);
	}
	ft_memfree((void**)saver);
	*saver = tmp;
	return (1);
}
​
int		remain_saver(char **saver, char **line, char *buf, int byte)
{
	char	*cut_ptr;
​
	if (buf)
		ft_memfree((void**)&buf);
	if (byte < 0)
		return (-1);
	if (!(*saver))
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	if ((cut_ptr = ft_strchr(*saver, '\n')))
		return (cut_newline(saver, line, cut_ptr));
	*line = *saver;
	return (0);
}
​
int		get_next_line(int fd, char **line)
{
	char		*buf;
	int			byte;
	static char	*saver;
	char		*cut_ptr;
​
	if (BUFFER_SIZE <= 0 || fd < 0 || !line)
		return (-1);
	if (!(buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((byte = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[byte] = 0;
		saver = ft_strjoin(saver, buf);
		if ((cut_ptr = ft_strchr(saver, '\n')))
			return (cut_newline(&saver, line, cut_ptr));
	}
	return (remain_saver(&saver, line, buf, byte));
}

int	main()
{
	char	*f_path = "gnltest.txt";
	char	*line;
	int		fd;
	int		rt;
	
	if ((fd = open(f_path, O_RDONLY)) == -1)
	{
		ft_putstr("File Not Open\n");
		return (0);
	}
	ft_putstr("Open Success\n");
	while ((rt = get_next_line(fd, &line)))
	{
		if (rt == -1)
		{
			ft_putstr("Read error\n");
			free(line);
		}
		ft_putstr("main :");
		ft_putstr(line);
		free(line);
		ft_putstr("\n");
	}
	if (rt == 0)
		ft_putstr("read end\n");
	close(fd);
}
