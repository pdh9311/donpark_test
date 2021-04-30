#include "ft_printf.h"

char	*check_flag(char *tag, t_info *info)
{
	char	*flags;
	char	*is_flag;

	flags = "-0";
	while (*tag != '\0' && (is_flag = ft_strchr(flags, *tag)) != 0)
	{
		if (*is_flag == '-')
			info->hyphen = 1;
		else if (*is_flag == '0')
			info->zero = 1;
		tag++;
	}
	if (tag == 0)
		return (0);
	return (tag);
}

int		star_num(va_list ap, char **tag, int *error, t_info *info)
{
	int		ret;

	ret = 0;
	if (**tag != '\0' && (**tag >= '0' && **tag <= '9'))
	{
		while (**tag != '\0' && (**tag >= '0' && **tag <= '9'))
		{
			ret = ret * 10 + (**tag) - '0';
			(*tag)++;
		}
	}
	else if (**tag != '\0' && **tag == '*')
	{
		(*tag)++;
		if (info->p_exist == DOTNUM)
			info->p_star = YES;
		ret = va_arg(ap, int);
	}
	if (ret > 2147483646)
		return (0);
	*error = NO;
	return (ret);
}

char	*check_width(va_list ap, char *tag, t_info *info)
{
	int		width_num;
	int		error;

	error = YES;
	width_num = 0;
	if (!(width_num = star_num(ap, &tag, &error, info)) && error == YES)
		return (0);
	if (width_num < 0)
	{
		width_num *= -1;
		info->hyphen = YES;
	}
	info->w_num = width_num;
	return (tag);
}

char	*check_precision(va_list ap, char *tag, t_info *info)
{
	int		prec_num;
	int		error;
	int		sign;

	error = YES;
	sign = 1;
	prec_num = 0;
	if (*tag == '.')
	{
		tag++;
		if (*tag != '\0' && *tag == '-')
		{
			sign *= -1;
			tag++;
		}
		if (*tag != '\0' && !(*tag >= '0' && *tag <= '9') && *tag != '*')
			info->p_exist = ONLYDOT;
		else
			info->p_exist = DOTNUM;
		if (!(prec_num = star_num(ap, &tag, &error, info)) && error == YES)
			return (0);
	}
	info->p_num = sign * prec_num;
	return (tag);
}

char	*check_info(va_list ap, char *tag, t_info *info)
{
	if (!ap || !tag)
		return (0);
	if (!(tag = check_flag(tag, info)))
		return (0);
	if (!(tag = check_width(ap, tag, info)))
		return (0);
	if (!(tag = check_precision(ap, tag, info)))
		return (0);
	return (tag);
}
