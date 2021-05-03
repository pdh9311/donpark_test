#include "ft_printf.h"

int		hexlen(size_t num)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

char	*chg_to_hex(size_t num, char *tag)
{
	char	*hex_str;
	int		len;
	char	*hex;

	len = hexlen(num);
	if (!(hex_str = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	if (*tag == 'x' || *tag == 'p')
		hex = "0123456789abcdef";
	else if (*tag == 'X')
		hex = "0123456789ABCDEF";
	while (len > 0)
	{
		hex_str[len - 1] = hex[num % 16];
		num /= 16;
		len--;
	}
	return (hex_str);
}

char	*ft_strdup(char *str)
{
	char	*new_str;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	if (!(new_str = (char *)malloc(len + 1)))
		return (0);
	new_str[len] = '\0';
	while (len--)
		new_str[len] = str[len];
	return (new_str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	int		i;
	
	if (!s1 && !s2)
		return (0);
	else if (!s1 && s2)
		return (ft_strdup(s2));
	else if (s1 && !s2)
		return (ft_strdup(s1));
	else
	{
		if (!(strjoin = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (0);
		i = 0;
		while (*s1)
			strjoin[i++] = *(s1++);
		while (*s2)
			strjoin[i++] = *(s2++);
		strjoin[i] = '\0';
	}
	return (strjoin);
}
