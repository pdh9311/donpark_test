/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 05:28:33 by donpark           #+#    #+#             */
/*   Updated: 2021/05/02 05:30:45 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_zero(t_info info, ssize_t num, int *ret)
{
	if (num == 0 && ((info.p_exist == DOTNUM && info.p_num == 0)
				|| info.p_exist == ONLYDOT))
	{
		*ret += info.w_num;
		while (info.w_num--)
			write(1, " ", 1);
		return (1);
	}
	return (0);
}

int		apply_to_int(va_list ap, t_info info, int *ret)
{
	char		*int_str;
	ssize_t		num;
	int			sign;

	sign = 1;
	num = va_arg(ap, int);
	if (num < 0)
	{
		sign *= -1;
		(*ret)++;
	}
	if (!(int_str = ft_itoa(num * sign)))
		return (0);
	if (info.p_num < 0 && info.p_star == NO)
		return (0);
	if (check_zero(info, num, ret))
		return (1);
	*ret += print_int(int_str, info, sign);
	free(int_str);
	int_str = 0;
	return (1);
}

int		apply_to_unint(va_list ap, t_info info, int *ret)
{
	char			*unint_str;
	unsigned int	un_num;
	int				sign;

	sign = 1;
	un_num = va_arg(ap, unsigned int);
	if (!(unint_str = ft_itoa(un_num)))
		return (0);
	if (info.p_num < 0 && info.p_star == NO)
		return (0);
	if (check_zero(info, un_num, ret))
		return (1);
	*ret += print_int(unint_str, info, sign);
	free(unint_str);
	unint_str = 0;
	return (1);
}

int		apply_to_hex(va_list ap, char *tag, t_info info, int *ret)
{
	char			*hex_str;
	unsigned int	hex;
	int				sign;

	sign = 1;
	hex = va_arg(ap, unsigned int);
	if (!(hex_str = chg_to_hex(hex, tag)))
		return (0);
	if (info.p_num < 0 && info.p_star == NO)
		return (0);
	if (check_zero(info, hex, ret))
		return (1);
	*ret += print_int(hex_str, info, sign);
	free(hex_str);
	hex_str = 0;
	return (1);
}
