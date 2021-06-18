#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int 	x = 10;
	int		y = 2;
	int		**m;

	m = (int **)malloc(sizeof(int *) * x);
	for (int i = 0; i < x; i++)
		m[i] = (int *)malloc(sizeof(int) * y);

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			m[i][j] = i + j;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < x; i++)
		free(m[i]);
	free(m);
	return (0);
}
