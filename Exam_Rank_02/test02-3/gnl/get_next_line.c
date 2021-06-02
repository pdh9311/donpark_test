#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	int		i;
	
	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return ((s1 == 0) ? ft_strdup(s2) : ft_strdup(s1));
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

int		is_newline(char *s)
{
	int		i;

	 i = 0;
	 while (s[i])
	 {
		 if (s[i] == '\n')
			 return (i);
		 i++;
	 }
	 return (-1);
}

int		split_line(char **backup, char **line, int cut_idx, char *buf)
{
	char	*tmp;
	int		len;

	if (buf)
		free(buf);
	(*backup)[cut_idx] = '\0';
	if (!(*line = ft_strdup(*backup)))
		return (-1);
	len = ft_strlen(*backup + cut_idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	if (!(tmp = ft_strdup(*backup + cut_idx + 1)))
		return (-1);
	if (*backup)
		free(*backup);
	*backup = tmp;
	return (1);
}

int		remains_data(char **backup, char **line, int read_size, char *buf)
{
	int		cut_idx;

	if (buf)
	{
		free(buf);
		buf = 0;
	}
	if (read_size < 0)
	{
		free(*backup);
		return (-1);
	}
	if (*backup && (cut_idx = is_newline(*backup)) != -1)
		return (split_line(backup, line, cut_idx, buf));
	if (*backup)
	{
		*line = *backup;
		*backup = 0;
	}
	else
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	return (0);
}

int		get_next_line(char **line)
{
	int			read_size;
	char		*buf;
	static char	*backup;
	int			cut_idx;
	char		*tmp;

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((read_size = read(0, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if (!(tmp = ft_strjoin(backup, buf)))
			return (-1);
		if (backup)
			free(backup);
		backup = tmp;
		if ((cut_idx = is_newline(backup)) != -1)
			return (split_line(&backup, line, cut_idx, buf));
	}
	return (remains_data(&backup, line, read_size, buf));
}
