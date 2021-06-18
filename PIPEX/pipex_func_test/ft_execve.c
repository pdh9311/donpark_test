#include <stdio.h>
#include <unistd.h>
/*
int	main(void)
{
	char *const	cmd[] = {"/usr/bin/ls", "-l", NULL};	// filename
	if (execve("/usr/bin/ls", cmd, NULL) == -1)
		perror("execve() fail!");
	return (0);
}
*/

int	main(int argc, char *argv[], char **env)
{
	int	i;

	for (i = 0; i < argc; i++)
		printf("argv[%d] : %s\n", i, argv[i]);
	printf("argv[%d] : %s\n", i, argv[i]);
	argv[0] = "ls";	// "/usr/bin/ls"
	argv[1] = "-l";
	if (execve("/usr/bin/ls", (char *const *)argv, NULL) == -1)
		printf("\nexecve() fail\n");
	return (0);
}
