#include "ft_printf.h"
#include <stdio.h>
void	print_info(t_info info)
{
	printf("\nhyphen: %d\t", info.hyphen);
	printf("zero: %d\t", info.zero);
	printf("w_num: %d\t", info.w_num);
	printf("p_num: %d\t", info.p_num);
	printf("p_exist: %d\t", info.p_exist);
	printf("p_star: %d\n", info.p_star);
}



int		main(void)
{

	ft_printf("|%5.0x|", 0);

//	ft_printf("|%.0d|", 33);
//	printf("\n|%.0d|\n", 33);
/*	
	ft_printf("|%8.5d|", 12);
	printf("|%8.5d|\n", 12);
	
	ft_printf("|%8.5d|", -12);
	printf("|%8.5d|\n", -12);

	ft_printf("|%08.5d|", -12);
	printf("|%08.5d|\n", -12);

	ft_printf("|%08d|", -12);
	printf("|%08d|\n", -12);

	ft_printf("|%08.*d|", -5, -12);
	printf("|%08.*d|\n", -5, -12);
*/
/*
	char	*tmp;
	tmp = NULL;
	ft_printf("|%p|", tmp);
	printf("\n");
	tmp = "test";
	ft_printf("|%p|", tmp);
*/
	return (0);
}
