#include "get_next_line.h"

int		find_nl(char *save, char n)
{
	int		idx;

	idx = 0;
	while (save[idx])
	{
		if (save[idx] == n)
			return (idx);
		idx++;
	}
	return (-1);
}

int		cut_string(char **save, char **line, int cut_point, char *buf)
{
	char	*tmp;

	if (buf)
	{
		free(buf);
		buf = 0;
	}
	(*save)[cut_point] = '\0';
	if (!(*line = ft_strdup(*save)) ||
				!(tmp = ft_strdup((*save) + cut_point + 1)))
	{
		free(*save);
		*save = 0;
		return (-1);
	}
	free(*save);
	*save = tmp;
	return (1);
}

int		put_all(char **save, char **line, ssize_t offset, char *buf)
{
	int		cut_point;

	if (buf)
	{
		free(buf);
		buf = 0;
	}
	if (offset < 0)
		return (-1);
	if (*save && ((cut_point = find_nl(*save, '\n')) >= 0))
		return (cut_string(save, line, cut_point, buf));
	if (*save)
	{
		*line = *save;
		*save = 0;
	}
	else
	{
		if (!(*line = ft_strdup("")))
			return (-1);
	}
	return (0);
}

char	*set_save(char *save, char *buf)
{
	char	*tmp;

	if (save)
		tmp = ft_strjoin(save, buf);
	else
		tmp = ft_strdup(buf);
	if (tmp == 0)
	{
		free(buf);
		buf = 0;
		return (NULL);
	}
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	ssize_t			offset;
	int				cut_point;
	static char		*save[OPEN_MAX];
	char			*tmp;
	char			*buf;
	
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (-1);
	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((offset = read(fd, buf, BUFFER_SIZE)) > 0)//fd를 반복문으로 읽어들임.
	{
		buf[offset] = '\0';
		if (!(tmp = set_save(save[fd], buf)))//저장된 save[fd]와 받아온 buf로 save[fd]를 구성하는 함수
			return (-1);
		printf("1save[fd]:	%s\t%p\n", save[fd], save[fd]);
		if (save[fd])//옛날 save를 해제시켜줌.
			free(save[fd]);
		save[fd] = tmp;
		if ((cut_point = find_nl(save[fd], '\n')) >= 0)//새로 구성된 save[fd]에서 \n을 찾아 idx를 반환
			return (cut_string(&save[fd], line, cut_point, buf)); //cut_point에 해당하는 위치에 null을 넣고 
																														//그 이전 값은 line에 이후 값은 save[fd]에 담아줍니다.
	}
	return (put_all(&save[fd], line, offset, buf)); //더 이상 받아올 버퍼가 없거나 read를 실패한경우 put_all에서 line출력을 담당합니다.
}
