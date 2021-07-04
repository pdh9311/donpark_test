/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:14:43 by donpark           #+#    #+#             */
/*   Updated: 2021/01/27 16:44:23 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		if (!(substr = (char *)ft_calloc(1, sizeof(char))))
			return (0);
		return (substr);
	}
	if (!(substr = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	i = 0;
	while (s[i] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}
