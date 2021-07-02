#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long 	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!(ptr = (void *)malloc(count * size)))
		return (0);
	ft_memset(ptr, 0, count * size);
	return (ptr);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize != 0)
	{
		while (src[i] && (i + 1) < dstsize)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}

char	*ft_strdup(const char *s1)
{
	char	*dst;

	if (!(dst = (char *)ft_calloc(ft_strlen((char *)s1) + 1, sizeof(char))))
		return (0);
	ft_strlcpy(dst, s1, ft_strlen((char *)s1) + 1);
	return (dst);
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

char	*str_ablankb(char *a, char *b)
{
	int		i;
	int		len;
	char	*new_str;
	char	*tmp1;
	char	*tmp2;


	i = 0;
	tmp1 = a;
	tmp2 = b;
	len = ft_strlen(a) + ft_strlen(b) + 1;
	if (!(new_str = (char *)malloc(len + 1)))
		return (0);

	while (*tmp1)
		new_str[i++] = *(tmp1++);
	new_str[i++] = ' ';
	while (*tmp2)
		new_str[i++] = *(tmp2++);
	new_str[i] = '\0';
	return (new_str);
}

int		is_not_double(int *arr, int random, int end)
{
	int		i;

	i = 0;
	while (i < end)
	{
		if (arr[i] == random)
			return (0);
		i++;
	}
	return (i);
}

int		main(int argc, char *argv[])
{
	char	*random_nums;
	char	*backup;
	char	*temp;

	int		random;
	int		size;
	int		*arr;
	int		i;

	backup == NULL;
	random_nums = NULL;
	srand(time(NULL));
	// random = rand();
	if (argc == 2)
	{
		if ((size = ft_atoi(argv[1])) <= 0)
			return (0);
		else
		{
			if (!(arr = (int *)malloc(sizeof(int) * size)))
				return (0);
			i = 0;
			while (i < size)
			{
				// random = rand();
				// random = rand() % size;
				// random = rand() % size + 1;
				random = rand() % size - (int)(ft_atoi(argv[1]) / 2);
				if (is_not_double(arr, random, i) || i == 0)
					arr[i] = random;
				else
					i--;
				i++;
			}
			// for(int i = 0; i < size; i++)
			// 	printf("arr[%d] : %d\n", i, arr[i]);
			i = 0;
			while (i < size)
			{
				temp = ft_itoa(arr[i]);
				if (i > 0)
				{
					backup = str_ablankb(random_nums, temp);
					if (temp)
						free(temp);
				}
				if (random_nums)
					free(random_nums);
				if (i == 0)
					random_nums = temp;
				else
					random_nums = backup;
				// printf("random_nums: \"%s\"\n", random_nums);
				i++;
			}
			setenv("ARG", random_nums, 0);
			// system("./push_swap $ARG");
			// system("valgrind --leak-check=yes ./push_swap $ARG");
			system("./push_swap $ARG | wc -l");
			system("./push_swap $ARG | ./checker $ARG");
			system("./push_swap $ARG | ./checker_linux $ARG");
			free(random_nums);
			free(arr);
		}
	}
	else
		printf("Please input argument\n");
	return (0);
}
