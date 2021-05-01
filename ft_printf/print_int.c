#include "ft_printf.h"

void	is_hyphen2(char *str, int blank, int p_blank, int sign)
{
	if (sign < 0)
		write(1, "-", 1);
	while (p_blank--)
		write(1, "0", 1);
	write(1, str, ft_strlen(str));
	if (blank > 0)
		while (blank--)
			write(1, " ", 1);
}

void	no_hyphen2(char *str, int blank, t_info info, int sign)
{
	char	*hy_zero;
	int		str_len;
	int		p_blank;
	int		flag;

	flag = 0;
	str_len = ft_strlen(str);
	p_blank = (info.p_num > str_len) ? (info.p_num - str_len) : 0;
	hy_zero = (info.zero == YES && (info.p_exist == NODOT || info.p_num < 0)) ? "0" : " ";
	if (sign < 0 && info.zero == YES && blank > 0 && (info.p_num < 0 || info.p_exist == NODOT))
	{
		write(1, "-", 1);
		flag = 1;
	}
	if (blank > 0)
		while (blank--)
			write(1, hy_zero, 1);
	if (sign < 0 && flag == 0)
		write(1, "-", 1);
	while (p_blank--)
		write(1, "0", 1);
	write(1, str, ft_strlen(str));
}

int		print_int(char *str, t_info info, int sign)
{
	int		str_len;
	int		blank;
	int		p_blank;
	int		ret;
printf("[str: %s]\n", str);
	blank = 0;
	str_len = ft_strlen(str);
	p_blank = (info.p_num > str_len) ? (info.p_num - str_len) : 0;
	ret = p_blank + str_len;
	blank = (p_blank > 0) ? (info.w_num - info.p_num) : (info.w_num - str_len);
	if (sign < 0)
		blank--;
	if (blank > 0)
		ret += blank;
	if (info.hyphen == YES)
		is_hyphen2(str, blank, p_blank, sign);
	else
		no_hyphen2(str, blank, info, sign);
	return (ret);
}
/* type이 d,i,u,x,X 와 같이 숫자를 인자로 가지는 경우
	정밀도값이 숫자의 길이보다 클 경우 빈 공간을 0으로 채운다.
	정밀도값이 숫자의 길이보다 같거나 작은 경우는 무시 된다.

	// precision value > numlen
	printf("%%.5d\t: |%.5d|\n", 12);		// |00012|
	printf("%%.9d\t: |%.9d|\n\n", 12);		// |000000012|

	// precision value <= numlen
	printf("%%.d\t: |%.d|\n", 12345);		//	|12345|
	printf("%%.0d\t: |%.0d|\n", 12345);		//	|12345|
	printf("%%.*d\t: |%.*d|\n", -5, 12345);	//	|12345|
	printf("%%.3d\t: |%.3d|\n", 12345);		//	|12345|
	printf("%%.5d\t: |%.5d|\n", 12345);		//	|12345|
* /
