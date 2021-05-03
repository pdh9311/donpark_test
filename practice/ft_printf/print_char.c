#include "ft_printf.h"

void	is_hyphen1(char *hy_zero, char *str, int blank, size_t len)
{
	write(1, str, len);
	while (blank--)
		write(1, hy_zero, 1);
}

void	no_hyphen1(char *hy_zero, char *str, int blank, size_t len)
{
	while (blank--)
		write(1, hy_zero, 1);
	write(1, str, len);
}

int		print_char(char *tag, char *str, t_info info, size_t len)
{
	char	*hy_zero;
	int		blank;
	int		ret;

	hy_zero = " ";
	if (*tag == '%' && info.zero == YES && info.hyphen == NO)
		hy_zero = "0";
	if ((int)len > info.w_num)
		blank = 0;
	else
		blank = info.w_num - len;
	ret = len + blank;
	if (info.hyphen == YES)
		is_hyphen1(hy_zero, str, blank, len);
	else
		no_hyphen1(hy_zero, str, blank, len);
	return (ret);

}
