#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{
	printf("|%x|\t", 123);
	ft_printf("|%x|", 123);
	printf("\n|%x|\t", -123);
	ft_printf("|%x|", -123);

	return (0);
}
