#include <unistd.h>
#define ASCII 128

void	ft_union(char *s1, char *s2)
{
	int		i;
	int		arr[ASCII];

	i = 0;
	while (i < ASCII)
		arr[i++] = 0;
	i = -1;
	while (s1[++i])
	{
		if (arr[(int)s1[i]] != 1)
		{
			write(1, &s1[i], 1);
			arr[(int)s1[i]] = 1;
		}
	}
	i = -1;
	while (s2[++i])
	{
		if (arr[(int)s2[i]] != 1)
		{
			write(1, &s2[i], 1);
			arr[(int)s2[i]] = 1;
		}
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
