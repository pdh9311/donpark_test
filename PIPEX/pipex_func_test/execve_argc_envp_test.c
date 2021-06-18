#include <stdio.h>
#include <unistd.h>

int	main(int argc, char *argv[], char **env)
{
	int	i;

	printf("=========================\n");
	i = 0;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
	printf("=========================\n");
	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
