#include "ft_printf.h"
// 플래그 : -0.*
int	main(void)
{
/*
	ft_printf("%c", 'a');			// 문자
	printf("\n");
	ft_printf("%s", "Hello");		// 문자열
	printf("\n");
	ft_printf("%p", "Hello");		// 포인터의 메모리 주소
	printf("\n");
	ft_printf("%d %d", 10, -10);	// 부호 있는 10진 정수
	printf("\n");
	ft_printf("%i %i", 20, -20);	// 부호 있는 10진 정수
	printf("\n");
	ft_printf("%u", 30);			// 부호 없는 10진 정수
	printf("\n");
	ft_printf("%x", 15);			// 부호 없는 16진 정수(소문자)
	printf("\n");
	ft_printf("%X", 15);			// 부호 없는 16진 정수(대문자)
	printf("\n");
	ft_printf("%%");				// %기호 출력
	printf("\n");
*/
	int ret = 0;
	ret = ft_printf("%----0-0d",10);
	printf("\n%d\n", ret);
	return (0);
}
