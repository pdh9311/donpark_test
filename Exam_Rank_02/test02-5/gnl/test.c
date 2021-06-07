#include <stdio.h>
#include "get_next_line.h"

int		main(void)
{
	int		ret;
	char	*line;

	printf("============================\n");
	while ((ret = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = 0;
	}
	printf("%s", line);
	free(line);
	line = 0;
	printf("============================\n");
	return (0);
}
