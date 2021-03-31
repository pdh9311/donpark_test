#include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <stdio.h>

int	g_cnt;

int main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open("gnltest.txt", O_RDWR);
	while ((ret = get_next_line(fd, &line)) > 0)
	{	g_cnt++;
		printf("(%d) %s\n", g_cnt, line);
		free(line);
	}
	g_cnt++;
	printf("(%d) %s\n", g_cnt, line);
	free(line);
	
	close(fd);
	return (0);
}
