/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 04:31:31 by donpark           #+#    #+#             */
/*   Updated: 2021/01/27 16:51:55 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcnt(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			cnt++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (cnt);
}

static char		*ft_worddup(char const *s, char c)
{
	char	*word;
	size_t	w_len;

	w_len = 0;
	while (s[w_len] && s[w_len] != c)
		w_len++;
	if (!(word = (char *)ft_calloc(w_len + 1, sizeof(char))))
		return (0);
	ft_strlcpy(word, s, w_len + 1);
	return (word);
}

static char		**ft_freeall(char **dptr)
{
	size_t	i;

	i = 0;
	while (dptr[i] != 0)
	{
		free(dptr[i]);
		i++;
	}
	free(dptr);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**words;
	size_t	w_cnt;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	w_cnt = ft_wordcnt(s, c);
	if (!(words = (char **)ft_calloc(w_cnt + 1, sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	while (i < w_cnt && s[j])
	{
		if (s[j] != c)
		{
			if (!(words[i++] = ft_worddup(&s[j], c)))
				return (ft_freeall(words));
			while (s[j] && s[j] != c)
				j++;
		}
		else
			j++;
	}
	return (words);
}
