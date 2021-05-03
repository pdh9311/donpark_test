#include "ft_printf.h"

int		apply_to_percent(char *tag, t_info info, int *ret)
{
	int		len;

	len  = 1;
	if (info.p_num < 0 && info.p_star == NO)
		return (0);
	*ret += print_char(tag, "%", info, len);
	return (1);
}
