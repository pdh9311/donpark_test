// pcsp : percent, char, string, pointer
#include "ft_printf.h"

int		apply_to_percent(char *tag, t_info info, int *ret)
{
	int		len;

	if (info.p_num < 0 && info.p_star == NO)
		return (0);
	len = 1;
	*ret += print_char(tag, "%", info, len);
	return (1);
}
/* type이 % 일때
	[precision] 옵션이 올 수 있지만 대부분 모두 무시 된다.
	만약 아래와 같이 정밀도 위치에 인자 값으로 받아 오는게 아니라 그냥 음수로 들어올 경우 warning error 가 발생한다.
	printf("|%5.-5%|");		// warning
	printf("|%5.*%|", -5);	// (상관없음) 정밀도가 음수인 경우 정밀도는 무시된다.
*/
int		apply_to_char(va_list ap, char *tag, t_info info, int *ret)
{
	char	c;
	int		len;

	c = va_arg(ap, int);
	if (info.p_exist == DOTNUM || info.zero == YES)
		return (0);
	len = 1;
	*ret += print_char(tag, &c, info, len);
	len = 1;
}
/* type이 c 일때
	아래와 같이 [flag] 옵션에 0이 들어 있는 경우와 [precision] 옵션에 ".숫자" 와 같이 올 경우 warning error가 발생한다.
	printf("%%0c\t: |%0c|\n", 'a');			// warning
	printf("%%.c\t: |%.c|\n", 'a');			// (상관없음)
	printf("%%.0c\t: |%.0c|\n", 'a');		// warning
	printf("%%.5c\t: |%.5c|\n", 'a');		// warning
	printf("%%.*c\t: |%.*c|\n", 0, 'a');	// warning
	printf("%%.*c\t: |%.*c|\n", 3, 'a');	// warning
*/
int		apply_to_str(va_list ap, char *tag, t_info info, int *ret)
{
	char	*str;
	int		len;

	if ((str = va_arg(ap, char *)) == NULL)
		str = "(null)";
	if (info.zero == YES || (info.p_exist == DOTNUM && info.p_num < 0 && info.p_star == NO))
		return (0);
	if ((info.p_exist == DOTNUM && info.p_num == 0) || info.p_exist == ONLYDOT)
	{
		*ret += info.w_num;
		while (info.w_num--)
			write(1, " ", 1);
		return (1);
	}
	len = ft_strlen(str);
	if (info.p_exist == DOTNUM && info.p_num > 0 && info.p_num < len)
		len = info.p_num;
	*ret += print_char(tag, str, info, len);
	return (1);
}
/* type이 s 일때
	1. 인자 값이 NULL 값이면 (null)을 출력한다.
	2. 아래의 두가지 경우 중 하나라도 해당되면 warning error가 발생한다.
		● [flag] 옵션에 0이 들어 있는 경우
		● [precision] 옵션에 *가 인자 값을 받아 오는게 아니라 그냥 음수로 들어올 경우 ex) printf("%.-5s", "test");
		printf("%%0s\t: |%0s|\n", "test");			// warning
		printf("%%.-5s\t: |%.-5s|\n\n", "test");	// warning
	3. 정밀도가 0인경우 문자열을 출력하지 않는다. 단, [width] 값이 있는 경우 width 값 만큼 공백을 출력한다.
	printf("%%.s\t: |%.s|\n", "test");		// ||
	printf("%%.0s\t: |%.0s|\n", "test");	// ||
	printf("%%5.s\t: |%5.s|\n", "test");	// |     |
	printf("%%5.0s\t: |%5.0s|\n", "test");	// |     |
	4. [precision] 옵션에 ".숫자"와 같이 오고, 숫자가 양수(+)라면,
	출력할 문자의 길이보다 정밀도가 작은 경우 문자열을 정밀도의 크기만큼 잘라서 출력한다.
	printf("%%.3s\t: |%.3s|\n", "test");	// |tes|
	printf("%%.5s\t: |%.5s|\n", "test");	// |test|
	printf("%%.*s\t: |%.*s|\n", 2, str);	// |te|
*/

int		apply_to_pointer(va_list ap, char *tag, t_info info, int *ret)
{
	void	*ptr;
	char	*hex_ptr;
	char	*ox_hex;
	size_t	tmp;

	ptr = va_arg(ap, void *);
	if (info.p_exist == DOTNUM || info.zero == YES)
		return (0);
	tmp = (size_t)ptr;
	hex_ptr = 0;
	if (!(hex_ptr = chg_to_hex(tmp, tag)))
		return (0);
	if (ptr == 0 && info.p_exist == ONLYDOT)
		*hex_ptr = '\0';
	ox_hex = ft_strjoin("0x", hex_ptr);
	free(hex_ptr);
	hex_ptr = 0;
	tmp = ft_strlen(ox_hex);
	*ret += print_char(tag, ox_hex, info, tmp);
	free(ox_hex);
	hex_ptr = 0;
	return (1);
}

