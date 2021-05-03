#include "ft_printf.h"

void	init_info(t_info *info)
{
	info->hyphen = 0;
	info->zero = 0;
	info->w_num = 0;
	info->p_num = 0;
	info->p_exist = 0;
	info->p_star = 0;
}

char	*manage_type(va_list ap, char *type, t_info info, int *ret)
{
	int		error_check;

	error_check = 0;
	if (*type == '%')
		error_check = apply_to_percent(type, info, ret);
	else if (*type == 'c')
		error_check = apply_to_char(ap, type, info, ret);
	else if (*type == 's')
		error_check = apply_to_str(ap, type, info, ret);
	else if (*type == 'p')
		error_check = apply_to_pointer(ap, type, info, ret);
	else if (*type == 'd' || *type == 'i')
		error_check = apply_to_int(ap, info, ret);
	else if (*type == 'u')
		error_check = apply_to_unint(ap, info, ret);
	else if (*type == 'x' || *type == 'X')
		error_check = apply_to_hex(ap, type, info, ret);
	else
		return (0);
	if (!error_check)
		return (0);
	return (type);
}

int		parse_format(va_list ap, char *format)
{
	int		ret;
	t_info 	tag_info;
	char	*curr;

	ret = 0;
	curr = format;
	while (*curr)
	{
		if (*curr == '%')
		{
			curr++;
			init_info(&tag_info);
			if (!(curr = check_info(ap, curr, &tag_info)))
				return (-1);
			if (!(curr = manage_type(ap, curr, tag_info, &ret)))
				return (-1);
		}
		else
		{
			write(1, curr, 1);
			ret++;
		}
		curr++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			cnt;

	cnt = 0;
	va_start(ap, format);
	if ((cnt = parse_format(ap, (char *)format)) < 0)
		return (-1);
	va_end(ap);
	return (cnt);
}
