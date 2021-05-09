#include "get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
#include <stdio.h>

int	g_cnt;

int main(void)
{
	char	*line;
	int		ret;
	
	line = NULL;
	printf("============================\n");	
	while ((ret = get_next_line(&line)) > 0)
	{	
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
	printf("============================\n");
//	while (1) {}
	return (0);
}
