/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_to_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 05:28:21 by donpark           #+#    #+#             */
/*   Updated: 2021/05/02 05:28:23 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_to_percent(char *tag, t_info info, int *ret)
{
	int		len;

	if (info.p_num < 0 && info.p_star == NO)
		return (0);
	len = 1;
	*ret += print_char(tag, "%", info, len);
	return (1);
}

int		apply_to_char(va_list ap, char *tag, t_info info, int *ret)
{
	char	c;
	int		len;

	c = va_arg(ap, int);
	if (info.p_exist == DOTNUM || info.zero == YES)
		return (0);
	len = 1;
	*ret += print_char(tag, &c, info, len);
	return (1);
}

int		apply_to_str(va_list ap, char *tag, t_info info, int *ret)
{
	char	*str;
	int		len;

	if ((str = va_arg(ap, char *)) == NULL)
		str = "(null)";
	if (info.zero == YES ||
			(info.p_exist == DOTNUM && info.p_num < 0 && info.p_star == NO))
		return (0);
	if ((info.p_exist == DOTNUM && info.p_num == 0) || info.p_exist == ONLYDOT)
	{
		*ret += info.w_num;
		while (info.w_num--)
			write(1, " ", 1);
		return (1);
	}
	len = ft_strlen(str);
	if (info.p_exist == DOTNUM && info.p_num > 0 && info.p_num < len)
		len = info.p_num;
	*ret += print_char(tag, str, info, len);
	return (1);
}

int		apply_to_pointer(va_list ap, char *tag, t_info info, int *ret)
{
	void	*ptr;
	char	*hex_ptr;
	char	*ox_hex;
	size_t	tmp;

	ptr = va_arg(ap, void *);
	if (info.p_exist == DOTNUM || info.zero == YES)
		return (0);
	tmp = (size_t)ptr;
	if (!(hex_ptr = chg_to_hex(tmp, tag)))
		return (0);
	if (ptr == 0 && info.p_exist == ONLYDOT)
		*hex_ptr = '\0';
	ox_hex = ft_strjoin("0x", hex_ptr);
	free(hex_ptr);
	hex_ptr = 0;
	*ret += print_char(tag, ox_hex, info, ft_strlen(ox_hex));
	free(ox_hex);
	ox_hex = 0;
	return (1);
}
