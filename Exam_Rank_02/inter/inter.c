#include <unistd.h>
#define ASCII 128

void	ft_inter(char *s1, char *s2)
{
	int	i;
	int	j;
	int	arr[ASCII];
	
	i = 0;
	while (i < ASCII)
		arr[i++] = 0;
	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j] && arr[(int)s1[i]] != 1)
			{
				write(1, &s1[i], 1);
				arr[(int)s1[i]] = 1; 
			}
			j++;
		}
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		ft_inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
