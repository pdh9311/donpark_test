#include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int result;

	result = 10;
	a = 4;
	result = ((a == 4) && (b = 1)) || ((a != 4) && (b = 2));
	printf("result : %d\n", result);
	printf("%d\n", b);
	return (0);
}
