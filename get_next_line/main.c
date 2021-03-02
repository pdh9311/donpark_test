#include "get_next_line.h"

#include <stdio.h>

int	g_cnt;

int main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open("test.txt", O_RDWR);
	// if (fd < 0)
	// {
	// 	printf("failed open file\n");
	// 	return (-1);
	// }
	// printf("successed open file | fd: %d\n", fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{	g_cnt++;
		printf("(%d)\t%s\n", g_cnt, line);
		free(line);
	}
	g_cnt++;
	printf("(%d)\t%s\n", g_cnt, line);
	free(line);

	return (0);
}
