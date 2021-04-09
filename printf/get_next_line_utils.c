/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunoh <seunoh@student.42.kr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:20:01 by seunoh            #+#    #+#             */
/*   Updated: 2021/04/07 14:20:01 by seunoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char	*ft_strdup(const char *s)
{
	int		tmp;
	char	*str;

	tmp = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * (tmp + 1))))
		return (NULL);
	tmp = 0;
	while (*s)
		str[tmp++] = *s++;
	str[tmp] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!(str = (char *)malloc(sizeof(char) *
				(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}
