#include <unistd.h>

int		is_not_double(char *s, char c, int idx)
{
	int		i;

	i = 0;
	while (s[i] && i < idx)
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_inter(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j] && is_not_double(s1, s2[j], i))
			{
				write(1, &s1[i], 1);
				break ;
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
