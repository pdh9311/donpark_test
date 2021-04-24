#include "ft_printf.h"

int	ft_parse_arg(va_list *ap, const char *format)
{
	const char	*curr;
	int			result;
	t_info		spec_info;

	curr = format;
	result = 0;
	while (*curr)
	{
		if (*curr == '%')
		{
			curr++;
			ft_init_info(&spec_info);
			if (!(curr = (const char *)ft_check_info(ap, curr, &spec_info)))
				return (-1);
			if (!(curr = ft_manage_spec(ap, curr, spec_info, &result)))
				return (-1);
		}
		else
		{
			ft_putchar_fd(*curr, 1);
			result++;
		}
		curr++;
	}
	return (result);
}
