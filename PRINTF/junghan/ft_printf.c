#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int		count;

	va_start(ap, format);
	if ((count = ft_parse_arg(&ap, format)) < 0)
		return (-1);
	va_end(ap);
	return (count);
}
