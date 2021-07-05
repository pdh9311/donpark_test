/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 07:43:43 by donpark           #+#    #+#             */
/*   Updated: 2021/01/26 19:52:22 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	max;
	size_t	b_len;
	size_t	l_len;

	i = 0;
	b_len = ft_strlen(big);
	l_len = ft_strlen(little);
	if (*little == '\0')
		return ((char *)big);
	if (b_len < l_len || l_len > len)
		return (0);
	max = b_len > len ? len - l_len : b_len - l_len;
	while (i <= max)
	{
		if (ft_strncmp(&big[i], little, l_len) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
