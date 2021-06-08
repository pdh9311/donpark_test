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

void	ft_union(char *s1, char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1[i])
	{
		if (is_not_double(s1, s1[i], i))
			write(1, &s1[i], 1);
		i++;
	}
	j = 0;
	while (s2[j])
	{
		if (is_not_double(s1, s2[j], i) && is_not_double(s2, s2[j], j))
			write(1, &s2[j], 1);
		j++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
