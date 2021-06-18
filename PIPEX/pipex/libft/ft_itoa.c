/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 06:58:40 by donpark           #+#    #+#             */
/*   Updated: 2021/01/25 12:39:44 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	size_t	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0) ? 1 : 0;
	n = (sign == 1) ? (n * -1) : n;
	len = ft_numlen(n);
	if (!(str = (char *)ft_calloc(len + sign + 1, sizeof(char))))
		return (0);
	str[len + sign] = '\0';
	while (len-- > 0)
	{
		str[len + sign] = n % 10 + '0';
		n /= 10;
	}
	str[0] = (sign == 1) ? '-' : str[0];
	return (str);
}
