#include <stdio.h>
// 플래그 : -0.*
// cspdiuxX%
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	num;

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

int	main(void)
{
	printf("%d\n",ft_atoi("12*(3123.244412"));

	char	*str;

	str = "123456789";
	printf("%s\t%p\n", str, str);
	str += 4;
	printf("%s\t%p\n", str, str);
	// printf("%c", 'a');			// 문자
	// printf("\n");
	// printf("%s", "Hello");		// 문자열
	// printf("\n");
	// printf("%p", "Hello");		// 포인터의 메모리 주소
	// printf("\n");
	// printf("%d %d", 10, -10);	// 부호 있는 10진 정수
	// printf("\n");
	// printf("%i %i", 20, -20);	// 부호 있는 10진 정수
	// printf("\n");
	// printf("%u", 30);			// 부호 없는 10진 정수
	// printf("\n");
	// printf("%x", 15);			// 부호 없는 16진 정수(소문자)
	// printf("\n");
	// printf("%X", 15);			// 부호 없는 16진 정수(대문자)
	// printf("\n");
	// printf("%%");				// %기호 출력
	// printf("\n");
	// int i = printf("123456%d",100);
	// printf("\n");
	// printf("i: %d\n", i);
	// printf("%d\n", printf("%"));

	// printf("%00010d\n", 10);
	// printf("%---10d\n ", 10);

	// char *tmp;
	// printf("%p\n", tmp);

	// printf("%*****d\n",1,2,3,4,5,999);
	// printf("% % %  vbd\n",10);
	// printf("%\n");

	return (0);
}
