#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i, j, tmp;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			j = 0;
			while (argv[2][j])
			{
				if (argv[1][i] == argv[2][j])
				{
					tmp = i;
					while (argv[1][--tmp] && tmp >= 0)
					{
						if (argv[1][i] == argv[1][tmp])
							break;
					}
					if (tmp < 0)
						write(1, &argv[1][i], 1);
					break;
				}
				j++;
			}
			i++;
		}
		
	}
	write(1, "\n", 1);
	return (0);
}
