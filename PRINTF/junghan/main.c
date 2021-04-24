#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("%-0d", 10);
	ft_printf("%****d",1,2,3,4,10);
	return (0);
}
