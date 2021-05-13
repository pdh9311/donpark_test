#include <unistd.h>
#define ASCII 256

int	main(int argc, char *argv[])
{
	int	i, j;
	int	ascii[ASCII];

	i = 0;
	while (i < ASCII)
		ascii[i++] = 0;

	if (argc == 3)
	{
		i = 1;
		while (i < 3)
		{
			j = 0;
			while (argv[i][j])
			{
				if (!(ascii[(unsigned char)argv[i][j]]))
				{
					write(1, &argv[i][j], 1);
					ascii[(unsigned char)argv[i][j]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
