#include "ft_printf.h"

int		ft_check_len(size_t num)
{
	int idx;

	idx = 0;
	while (num >= 16)
	{
		num /= 16;
		idx++;
	}
	return (idx);
}

char	*ft_chg_to_hex(size_t num, const char *spec)
{
	char	*hex;
	char	*result;
	int		idx;

	if (!(result = (char *)ft_calloc(sizeof(char), 13)))
		return (0);
	if (*spec == 'x' || *spec == 'p')
		hex = "0123456789abcdef";
	else if (*spec == 'X')
		hex = "0123456789ABCDEF";
	idx = ft_check_len(num);
	while (idx >= 0)
	{
		result[idx] = hex[num % 16];
		num = num / 16;
		idx--;
	}
	return (result);
}
