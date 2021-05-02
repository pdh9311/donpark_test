/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 05:30:13 by donpark           #+#    #+#             */
/*   Updated: 2021/05/02 05:31:03 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_hyphen2(char *str, int blank, int p_blank, int sign)
{
	if (sign < 0)
		write(1, "-", 1);
	while (p_blank--)
		write(1, "0", 1);
	write(1, str, ft_strlen(str));
	if (blank > 0)
		while (blank--)
			write(1, " ", 1);
}

void	no_hyphen2(char *str, int blank, t_info info, int sign)
{
	char	*hy_zero;
	int		str_len;
	int		p_blank;
	int		flag;

	flag = 0;
	str_len = ft_strlen(str);
	p_blank = (info.p_num > str_len) ? (info.p_num - str_len) : 0;
	hy_zero = (info.zero == YES &&
			(info.p_exist == NODOT || info.p_num < 0)) ? "0" : " ";
	if (sign < 0 && info.zero == YES && blank > 0 &&
			(info.p_num < 0 || info.p_exist == NODOT))
	{
		write(1, "-", 1);
		flag = 1;
	}
	if (blank > 0)
		while (blank--)
			write(1, hy_zero, 1);
	if (sign < 0 && flag == 0)
		write(1, "-", 1);
	while (p_blank--)
		write(1, "0", 1);
	write(1, str, ft_strlen(str));
}

int		print_int(char *str, t_info info, int sign)
{
	int		str_len;
	int		blank;
	int		p_blank;
	int		ret;

	blank = 0;
	str_len = ft_strlen(str);
	p_blank = (info.p_num > str_len) ? (info.p_num - str_len) : 0;
	ret = p_blank + str_len;
	blank = (p_blank > 0) ? (info.w_num - info.p_num) : (info.w_num - str_len);
	if (sign < 0)
		blank--;
	if (blank > 0)
		ret += blank;
	if (info.hyphen == YES)
		is_hyphen2(str, blank, p_blank, sign);
	else
		no_hyphen2(str, blank, info, sign);
	return (ret);
}
