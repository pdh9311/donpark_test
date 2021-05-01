// diux : int(d,i), unsigned int(u), hex(x, X)
#include "ft_printf.h"

int		check_zero(t_info info, ssize_t num, int *ret)
{
	if (num == 0 && ((info.p_exist == DOTNUM && info.p_num == 0) || info.p_exist == ONLYDOT))
	{
		*ret += info.w_num;
		while (info.w_num--)
			write(1, " ", 1);
		return (1);
	}
	return (0);
}

int		apply_to_int(va_list ap, t_info info, int *ret)
{
	char		*int_str;
	ssize_t		num;
	int			sign;

	sign = 1;
	num = va_arg(ap, int);
	printf("(va: %ld)", num);
	if (num < 0)
	{
		sign *= -1;
		(*ret)++;
	}
	if (!(int_str = ft_itoa(num * sign)))
		return (0);
	printf("(int_str: %s)", int_str);
	if (info.p_num < 0 && info.p_star == NO)
		return (0);
	if (check_zero(info, num, ret))
		return (1);
	*ret += print_int(int_str, info, sign);
	free(int_str);
	int_str = 0;
	return (1);
}
/* type이 d 또는 i 일때
	1. [precision] 옵션에 *가 인자 값을 받아 오는게 아니라 그냥 음수로 들어올 경우 warning error가 발생한다.
	printf("%%.-5d\t: |%.-5d|\n", 10);	// warning
	2. 인자값이 0 인데 정밀도 옵션(.)이 있지만 정밀도값이 없거나 0 인경우, [width] 옵션의 값만큼 공백으로 출력한다.
	printf("%%.d\t: |%.d|\n", 0);		// ||
	printf("%%.0d\t: |%.0d|\n", 0);		// ||
	printf("%%5.d\t: |%5.d|\n", 0);		// |     |
	printf("%%5.0d\t: |%5.0d|\n", 0);	// |     |
*/

int		apply_to_unint(va_list ap, t_info info, int *ret)
{
	char			*unint_str;
	unsigned int	un_num;
	int				sign;

	sign = 1;
	un_num = va_arg(ap, unsigned int);
	if (!(unint_str = ft_itoa(un_num)))
		return (0);
	if (info.p_num < 0 && info.p_star == NO)
		return (0);
	if (check_zero(info, un_num, ret))
		return (1);
	*ret += print_int(unint_str, info, sign);
	free(unint_str);
	unint_str = 0;
	return (1);
}
/* type이 u 일때
	1. [precision] 옵션에 *가 인자 값을 받아 오는게 아니라 그냥 음수로 들어올 경우 warning error가 발생한다.
	printf("%%.-5u\t: |%.-5u|\n", 10);	// warning
	2. 인자값이 0 인데 정밀도 옵션(.)이 있지만 정밀도값이 없거나 0 인경우, [width] 옵션의 값만큼 공백으로 출력한다.
	printf("%%.u\t: |%.u|\n", 0);		// ||
	printf("%%.0u\t: |%.0u|\n", 0);		// ||
	printf("%%5.u\t: |%5.u|\n", 0);		// |     |
	printf("%%5.0u\t: |%5.0u|\n", 0);	// |     |
*/

int		apply_to_hex(va_list ap, char *tag, t_info info, int *ret)
{
	char			*hex_str;
	unsigned int	hex;
	int				sign;

	sign = 1;
	hex = va_arg(ap, unsigned int);
	if (!(hex_str = chg_to_hex(hex, tag)))
		return (0);
	if (info.p_num < 0 && info.p_star == NO)
		return (0);
	if (check_zero(info, hex, ret))
		return (1);
	*ret += print_int(hex_str, info, sign);
	free(hex_str);
	hex_str = 0;
	return (1);
}
