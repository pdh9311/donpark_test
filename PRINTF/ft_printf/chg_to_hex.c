#include "ft_printf.h"

int		check_len(size_t num)
{
	int		i;

	i = 0;
	while (i >= 16)
	{
		num /= 16;
		i++;
	}
	return (i);
}

char	*chg_to_hex(size_t num, char *tag)
{
	char	*hex;
	char	*ret;
	int		i;

	if (!(ret = (char *)ft_calloc(13, sizeof(char))))
		return (0);
	if (*tag == 'x' || *tag == 'p')
		hex = "0123456789abcdef";
	else if (*tag == 'X')
		hex = "0123456789ABCDEF";
	i = check_len(num);
	while (i >= 0)
	{
		ret[i] = hex[num % 16];
		num /= 16;
		i--;
	}
	return (ret);
}
