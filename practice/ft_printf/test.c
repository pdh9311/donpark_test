#include <stdio.h>
#include <stdlib.h>

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

size_t	ft_numlen(size_t n)
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

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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
	while (len--)
		new_str[len] = str[len];
	return (new_str);
}

int		main(void)
{
	ssize_t	num;
	char	*str;

	num = -21474836489;
	str = ft_itoa(num);
	printf("num: %zd\nstr: %s\n", num, str);
	printf("strdup: %s\n", ft_strdup(str));
}
