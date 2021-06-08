#include "pipex.h"

void	ft_memfree(char **mem)
{
	size_t		i;

	i = 0;
	while (mem[i])
	{

		i++;
	}
}

int		main(int argc, char *argv[])
{
	char	*file1;
	char	*file2;
	char	**cmd;
	int		i;

	file1 = argv[1];
	file2 = argv[argc - 1];
	if (!(cmd = (char **)malloc(sizeof(char *) * (argc - 3) + 1)))
		return (0);
	i = 0;
	while (i < (argc - 3))
	{
		if (!(cmd[i] = (char *)malloc(sizeof(char) * ft_strlen(cmd[i]
		cmd[i] = argv[i + 2];
		i++;
	}
	cmd[i] = '\0';

	return (0);
}
