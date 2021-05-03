#include "ft_printf.h"

char	*ft_strchr(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc(size_t count, int type)
{
	void 	*ret;
	size_t	i;

	i = 0;
	if (!(ret = (void *)malloc(count * type)))
		return (0);
	while (i < (count * type))
		((unsigned char *)ret)[i++] = 0;
	return (ret);
}

size_t	ft_numlen(ssize_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(ssize_t num)
{
	char	*str;
	size_t	len;
	int		sign;

	sign = 1;
	if (num < 0)
	{
		num *= -1;
		sign *= -1;
	}
	len = ft_numlen(num);
	if (sign == -1)
		len++;
	if (!(str = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	while (len > 0)
	{
		str[len - 1] = num % 10 + '0';
		num /= 10;
		len--;
	}
	str[0] = (sign == -1) ? '-' : str[0];
	return (str);
}
