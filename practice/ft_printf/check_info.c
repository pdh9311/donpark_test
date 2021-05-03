#include "ft_printf.h"

char	*check_flag(char *tag, t_info *info)
{
	char	*flags;
	char	*is_flag;

	is_flag = 0;
	flags = "-0";
	while (*tag != '\0' && (is_flag = ft_strchr(flags, *tag)) > 0)
	{
		if (*tag == '-')
			info->hyphen = 1;
		else
			info->zero = 1;
		tag++;
	}
	return (tag);
}

int		w_p_star_num(va_list ap, char **tag, int *error, t_info *info)
{
	int		w_p_num;

	w_p_num = 0;
	if (**tag != '\0' && (**tag >= '0' && **tag <= '9'))
	{
		while (**tag != '\0' && (**tag >= '0' && **tag <= '9'))
		{
			w_p_num = w_p_num * 10 + (**tag) - '0';
			(*tag)++;
		}
	}
	else if (**tag != '\0' && **tag == '*')
	{
		w_p_num = va_arg(ap, int);
		if (info->p_exist == DOTNUM)
			info->p_star = YES;
		(*tag)++;
	}
	if (w_p_num > 2147483646)
		return (0); 
	*error = NO;
	return (w_p_num);
}

char	*check_width(va_list ap, char *tag, t_info *info)
{
	int		error;
	int		width_num;

	width_num = 0;
	error = YES;
	if (!(width_num = w_p_star_num(ap, &tag, &error, info)) && error == YES)
		return (0);
	if (width_num < 0)
	{
		info->hyphen = YES;
		width_num *= -1;
	}
	info->w_num = width_num;
	return (tag);
}

char	*check_precision(va_list ap, char *tag, t_info *info)
{
	int		prec_num;
	int		error;
	int		sign;

	prec_num = 0;
	error = YES;
	sign = 1;
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

		if (!(prec_num = w_p_star_num(ap, &tag, &error, info)) && error == YES)
			return (0);
	}
	info->p_num = prec_num * sign;
	return (tag);
}


char	*check_info(va_list ap, char *tag, t_info *info)
{
	if (!ap || !info)
		return (0);
	if (!(tag = check_flag(tag, info)))
		return (0);
	if (!(tag = check_width(ap, tag, info)))
		return (0);
	if (!(tag = check_precision(ap, tag, info)))
		return (0);
	return (tag);
}
