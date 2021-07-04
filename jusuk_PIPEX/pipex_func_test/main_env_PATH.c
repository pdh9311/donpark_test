#include <stdio.h>
#include <unistd.h>

int		main(int argc, char *argv[], char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' &&
			env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
		{
			printf("%s", env[i]);	// env[i] + 5
			break ;
		}
		i++;
	}
}
