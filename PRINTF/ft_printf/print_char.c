#include "ft_printf.h"

void	is_hyphen1(char *hy_zero, char *str, int blank, size_t len)
{
	write(1, str, len);
	while (blank--)
		write(1, hy_zero, 1);
}

void	no_hyphen1(char *hy_zero, char *str, int blank, size_t len)
{
	while (blank--)
		write(1, hy_zero, 1);
	write(1, str, len);
}

int		print_char(char *tag, char *str, t_info info, size_t len)
{
	int		blank;
	char	*hy_zero;
	int		ret;

	hy_zero = " ";
	if (*tag == '%' && info.zero == YES && info.hyphen == NO)
		hy_zero = "0";
	if ((int)len > info.w_num)
		blank = 0;
	else
		blank = info.w_num - len;
	ret = blank + len;
	if (info.hyphen == YES)
		is_hyphen1(hy_zero, str, blank, len);
	else
		no_hyphen1(hy_zero, str, blank, len);
	return (ret);
}
/* [flag]의 0 옵션은 숫자와 %에만 적용된다. 
	printf("%%05%%\t: |%%|\n");
	printf("%%05d\t: |%05d|\n", 1);
	printf("%%05i\t: |%05i|\n", 2);
	printf("%%05u\t: |%05u|\n", 3);
	printf("%%05x\t: |%05x|\n", 123);
	printf("%%05X\t: |%05X|\n\n", 123);

//  printf("%%05c\t: |%05c|\n", 'a');		// warning
//  printf("%%05s\t: |%05s|\n", "test");	// warning
//  printf("%%05p\t: |%05p|\n", "test");	// warning
*/
