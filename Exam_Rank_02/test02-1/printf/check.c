#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	ft_printf("[%5.4s][%8.3d][%3.5x]", "abcdef", -1000, 999999);
	printf("\n[%5.4s][%8.3d][%3.5x]\n", "abcdef", -1000, 999999);

	return (0);
}
