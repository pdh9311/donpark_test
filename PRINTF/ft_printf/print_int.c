#include "ft_printf.h"

void	is_hyphen2(char *str, int width, int precnum, int sign)
{
	if (sign < 0)
		write(1, "-", 1);
	while (precnum--)
		write(1, str, ft_strlen(str));
	if (width > 0)
		while (width--)
			write(1, " ", 1);
}

void	no_hyphen2(char *str, int width, t_info info, int sign)
{
	char	*hy_zero;
	int		str_len;
	int		precnum;
	int		flag;

	flag = 0;
	str_len = ft_strlen(str);
	precnum = (info.p_num > str_len) ? (info.p_num - str_len) : 0;
	hy_zero = (info.zero == YES && (info.p_exist == NODOT || info.p_num < 0)) ? "0" : " ";
	if (sign < 0 && info.zero == YES && width > 0 && (info.p_num < 0 || info.p_exist == NODOT))
	{
		write(1, "-", 1);
		flag = 1;
	}
	if (width > 0)
		while (width--)
			write(1, hy_zero, 1);
	if (sign < 0 && flag == 0)
		write(1, "-", 1);
	while (precnum--)
		write(1, "0", 1);
	write(1, str, ft_strlen(str));
}

int		print_int(char *str, t_info info, int sign)
{
	int		str_len;
	int		width;
	int		precnum;
	int		ret;

	width = 0;
	str_len = ft_strlen(str);
	precnum = (info.p_num > str_len) ? (info.p_num - str_len) : 0;
	ret = precnum + str_len;
	width = (precnum > 0) ? (info.w_num - info.p_num) : (info.w_num - str_len);
	if (sign < 0)
		width--;
	if (width > 0)
		ret += width;
	if (info.hyphen == YES)
		is_hyphen2(str, width, precnum, sign);
	else
		no_hyphen2(str, width, info, sign);
	return (ret);
}
