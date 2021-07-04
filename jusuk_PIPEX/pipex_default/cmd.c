#include "pipex.h"

int		memory_free(char **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = 0;
		return (1);
	}
	return (0);
}

void	double_memory_free(char **mem)
{
	int		i;

	i = 0;
	while (mem[i])
	{
		free(mem[i]);
		mem[i] = 0;
		i++;
	}
	free(mem);
	mem = 0;
}

char	*find_path(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' &&
			env[i][2] == 'T' && env[i][3] == 'H' && env[i][4] == '=')
			return (env[i] + 5);
		i++;
	}
}

void	run_cmd(char *cmd, char **env)
{
	char	*export_path;
	char	**colon_split;
	char	**cmd_split;
	char	*slash_join;
	char	*executed_location;
	int		i;

	export_path = find_path(env);
	// printf("%s", export_path);
	colon_split = ft_split(export_path, ':');
	// i = 0;
	// while (colon_split[i])
	// 	printf("%s\n", colon_split[i++]);
	cmd_split = ft_split(cmd, ' ');
	// i = 0;
	// while (cmd_split[i])
	// 	printf("%s\n", cmd_split[i++]);
	i = 0;
	while (colon_split[i])
	{
		slash_join = ft_strjoin(colon_split[i], "/");
		executed_location = ft_strjoin(slash_join, cmd_split[0]);
		memory_free(&slash_join);
		// printf("executed_location: %s\n", executed_location);
		execve(executed_location, (char *const *)cmd_split, NULL);
		memory_free(&executed_location);
		i++;
	}
	// printf("execve() check\n");
	double_memory_free(colon_split);
	double_memory_free(cmd_split);
}

#if 0
int	main(int argc, char *argv[], char **env)
{
	run_cmd("grep a", env);
	printf("execve() check\n");
	return 0;
}
#endif
