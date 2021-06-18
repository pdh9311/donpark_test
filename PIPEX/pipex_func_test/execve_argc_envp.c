#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*argv[] = {"jim", "jams", NULL};
	char	*env[] = {"some", "environment", NULL};
	if (execve("./execve_argc_env_test", argv, env) == -1)
		perror("execve() fail!");
	return (0);
}
