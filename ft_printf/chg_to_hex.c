/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chg_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 05:29:07 by donpark           #+#    #+#             */
/*   Updated: 2021/05/02 05:29:08 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hexlen(size_t n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

char	*chg_to_hex(size_t num, char *tag)
{
	char	*hex;
	char	*ret;
	int		len;

	len = hexlen(num);
	if (!(ret = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	if (*tag == 'x' || *tag == 'p')
		hex = "0123456789abcdef";
	else if (*tag == 'X')
		hex = "0123456789ABCDEF";
	while (len > 0)
	{
		ret[len - 1] = hex[num % 16];
		num /= 16;
		len--;
	}
	return (ret);
}
