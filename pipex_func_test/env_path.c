#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

void	memory_free(char **mem)
{
	int		i;

	i = 0;
	while (mem[i])
	{
		free(mem[i]);
		mem[i] = 0;
		i++;
	}
	free(mem);
}

char **new_ft_split(char *str, int c)
{
    static char **ret;  // 리턴할 2차원 배열
    static int  count;  // 구분자를 기준으로 나눠진 문자열의 갯수
    char *chr_ret;      // ft_strchr함수의 리턴값을 받아줄 포인터변수

    if (str == NULL)
        return (ret);
	while (*str == c)
        str++;
	if (*str == '\0')
        return (ret);

    // 카운트를 하나씩 올리며 배열 재할당
    count++;

	// realloc은 허용되지 않은 함수이므로 과제 제출시에는 ft_realloc 같은 형태로 재정의해서 사용해야함
    ret = ft_realloc(ret, sizeof(char *) * (count + 1));
    if (ret == NULL)
        return (NULL);
    ret[count] = NULL;

	// 구분자 찾기
    chr_ret = ft_strchr(str, c);
	if (chr_ret == NULL)
    {
    	ret[count - 1] = ft_strdup(str);
        return (ret);
    }
    ret[count - 1] = ft_substr(str, 0, chr_ret - str);
    return (new_ft_split(chr_ret + 1, c));
}

int		main(int argc, char *argv[], char **env)
{
	printf("argc: %d\n", argc);

	int		i, j;
	for (i = 0; i < argc; i++)
		printf("argv[%d]: %s    ", i, argv[i]);
	printf("\n\n");
	printf("env list === \n");
	for (i = 0; env[i]; i++)
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' && env[i][3] == 'H')
		{
			printf("%s\n\n", env[i]);
			break ;
		}
	}

	char	**split;

	split = ft_split(&env[i][5], ':');
	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}
	memory_free(split);
	return (0);
}
/*
int main()
{
    char **str;
    int i = 0;

    str = new_ft_split("hello world", ' ');
    while (str[i])
        printf("%s\n", str[i++]);
}
*/
