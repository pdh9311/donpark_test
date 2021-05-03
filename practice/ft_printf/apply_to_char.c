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

int		apply_to_char(va_list ap, char *tag, t_info info, int *ret)
{
	int		len;
	char	c;

	len = 1;
	if (info.zero == YES || info.p_exist == DOTNUM)
		return (0);
	c = va_arg(ap, int);
	*ret += print_char(tag, &c, info, len);
	return (1);
}

int		apply_to_str(va_list ap, char *tag, t_info info, int *ret)
{
	int		len;
	char	*str;

	if ((str = va_arg(ap, char *)) == NULL) 
		str = "(null)";
	len = ft_strlen(str);
	if (info.zero == YES || (info.p_exist == DOTNUM && info.p_star == NO && info.p_num < 0))
		return (0);
	if (info.p_exist == ONLYDOT || (info.p_exist == DOTNUM && info.p_num == 0))
	{
		*ret += info.w_num;
		while (info.w_num--)
			write(1, " ", 1);
		return (1);
	}
	if (info.p_exist == DOTNUM && info.p_num > 0 && info.p_num < len)
		len = info.p_num;
	*ret += print_char(tag, str, info, len);
	return (1);	
}

int		apply_to_pointer(va_list ap, char *tag, t_info info, int *ret)
{
	void	*ptr;
	char	*hex_str;
	char	*ox_str;
	size_t	tmp;

	ptr = va_arg(ap, void *);
	tmp = (size_t)ptr;
	if (info.zero == YES || info.p_exist == DOTNUM)
		return (0);
	if (!(hex_str = chg_to_hex(tmp, tag)))
		return (0);
	if (info.p_exist == ONLYDOT && ptr == 0)
		*hex_str = '\0';
	ox_str = ft_strjoin("0x", hex_str);
	free(hex_str);
	hex_str = 0;
	*ret += print_char(tag, ox_str, info, ft_strlen(ox_str));
	free(ox_str);
	ox_str = 0;
	return (1);
}
