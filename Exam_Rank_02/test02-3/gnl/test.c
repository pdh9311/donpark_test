#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	char	*line;
	int		ret;

	printf("========================\n");
	while ((ret = get_next_line(&line) == 1))
	{
		printf("%s\n", line);
		free(line);
		line  = 0;
	}
	printf("%s", line);
	free(line);
	line = 0;
	printf("========================\n");
	return (0);
}
