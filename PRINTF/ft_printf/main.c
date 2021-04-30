#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	ft_printf("|%%|");
	printf("\t|%%|\n");

	ft_printf("|%5%|");
	printf("\t|%5%|\n");

	ft_printf("|%-5%|");
	printf("\t|%-5%|\n");
	
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	return (0);
}
