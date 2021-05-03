#include "ft_printf.h"

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
//	ft_printf("|%.0d|", 33);
//	printf("\n|%.0d|\n", 33);
	ft_printf("|%8.5d|", 12);
	printf("\n");
	ft_printf("|%8.5d|", -12);
	printf("\n");
	ft_printf("|%08.5d|", -12);
	printf("\n");
	ft_printf("|%08d|", -12);
	printf("\n");
	ft_printf("|%08.*d|", -5, -12);


	return (0);
}
