/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 05:29:14 by donpark           #+#    #+#             */
/*   Updated: 2021/05/02 05:29:15 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*manage_type(va_list ap, char *tag, t_info info, int *ret)
{
	int		error_check;

	error_check = 0;
	if (*tag == '%')
		error_check = apply_to_percent(tag, info, ret);
	else if (*tag == 'c')
		error_check = apply_to_char(ap, tag, info, ret);
	else if (*tag == 's')
		error_check = apply_to_str(ap, tag, info, ret);
	else if (*tag == 'p')
		error_check = apply_to_pointer(ap, tag, info, ret);
	else if (*tag == 'd' || *tag == 'i')
		error_check = apply_to_int(ap, info, ret);
	else if (*tag == 'u')
		error_check = apply_to_unint(ap, info, ret);
	else if (*tag == 'x' || *tag == 'X')
		error_check = apply_to_hex(ap, tag, info, ret);
	else
		return (0);
	if (!error_check)
		return (0);
	return (tag);
}

int		parse_format(va_list ap, char *format)
{
	int		ret;
	char	*curr;
	t_info	tag_info;

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
	va_list	ap;
	int		cnt;

	va_start(ap, format);
	cnt = 0;
	if ((cnt = parse_format(ap, (char *)format)) < 0)
		return (-1);
	va_end(ap);
	return (cnt);
}
