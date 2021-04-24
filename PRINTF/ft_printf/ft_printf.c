#include "ft_printf.h"


void	ft_init_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->w_asterisk = 0;
	info->dot = 0;
	info->precision = 0;
	info->p_asterisk = 0;
	info->type = 0;
}

char	*ft_check_flag(char *tag, t_info *info)
{
	char	*flags;
	char	*is_flag;

	flags = "-0";
	while ((is_flag = ft_strchr(flags, *tag)) != 0)
	{
		if (*tag == '-')
			info->minus = 1;
		else if (*tag == '0')
			info->zero = 1;
		printf("|%c|\t", *tag);
		tag++;
	}
	return (tag);
}

size_t	ft_numlen(int n)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_check_width(va_list *ap, char *tag, t_info *info)
{
	if (ft_isdigit(*tag))
	{
		info->width = ft_atoi(tag);
		tag += ft_numlen(ft_atoi(tag));
	}
	else if (*tag == '*')
	{
		info->width = va_arg(*ap, int);
		tag++;
		printf("width: %d\n", info->width);
	}
	return(tag);
}

char	*ft_check_precision(va_list *ap, char *tag, t_info *info)
{
	int prec;

	prec = 0;
	if (*tag == '.')
	{
		tag++;
		if (*tag == '*')
		{
			info->precision = va_arg(*ap, int);
			tag++;
		}
		else
		{
			prec = ft_atoi(tag);
			if (prec < 0)
				return (0);		// precision 에 .-3 과 같이 음수같이 왔을경우 오류
			info->precision = prec;
			tag += ft_numlen(prec);
		}
	}
	return (tag);
}

char	*ft_check_type(char *tag, t_info *info)
{
	char	*specifier;
	char	*is_specifier;
	// cspdiuxX%
	specifier = "cspdiuxX";
	if (*tag == '%' || (is_specifier = ft_strchr(specifier, *tag)) != 0)
	{
		info->type = *tag;
		tag++;
	}
	return (tag);
}

char	*ft_check_info(va_list *ap, char *tag, t_info *info)
{

	tag = ft_check_flag(tag, info);
	printf("minus:%d\tzero:%d\n", info->minus, info->zero);
	printf("curr_tag: %c\n", *tag);
	
	tag = ft_check_width(ap, tag, info);
	printf("width: %d\n", info->width);
	printf("curr_tag: %c\n", *tag);

	if (!(tag = ft_check_precision(ap, tag, info)))
		return (0);
	printf("precision: %d\n", info->precision);
	printf("curr_tag: %c\n", *tag);

	tag = ft_check_type(tag, info);
	printf("type: %c\n", info->type);
	printf("curr_tag: %c\n", *tag);

	return (tag);
}
////////////////////////////////////////////////////////////////

void	ft_write_tag(t_info *info, int *result)
{
	printf("info->type: %c\n", info->type);
	if (info->type == 'c')
		ft_write_char(info, result);
	else if (info->type == 's')
		ft_write_string(info, result);
	else if (info->type == 'd' || info->type == 'i')
		ft_write_int(info, result);
	else if (info->type == 'u')
		ft_write_unsignedint(info, result);
	else if (info->type == 'x')
		ft_write_smallhex(info, result);
	else if (info->type == 'X')
		ft_write_bighex(info, result);
}

////////////////////////////////////////////////////////////////
int		ft_format(va_list *ap, const char *format)
{
	int		result;
	char	*curr;
	t_info	tag_info;

	result = 0;
	curr = (char *)format;
	while (*curr)
	{
		if (*curr == '%')
		{
			curr++;
			if (*curr == '%')
				write(1, curr, 1);
			ft_init_info(&tag_info);
			if (!(curr = ft_check_info(ap, curr, &tag_info)))
				return (-1);
			printf("tag_info.type : %c\n", tag_info.type);
			if (tag_info.type)
				ft_write_tag(&tag_info, &result);
		}
		else
		{
			write(1, curr, 1);
			result++;
		}
		curr++;
	}
	return (result);
}

int		ft_printf(const char *format,...)
{
	va_list	ap;
	int		cnt;
	cnt = 0;
	va_start(ap, format);
	if ((cnt = ft_format(&ap, format)) < 0)
		return (-1);
	printf("format : %s\n", format);
	va_end(ap);
	return (cnt);
}

int		main(void)
{
	int ret = 0;
	ret = ft_printf("%----0-0123123.2654cADVDew3", 10, 'a');
	printf("\nret : %d\n", ret);
	return (0);
}
