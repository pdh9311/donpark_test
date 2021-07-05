#include "push_swap.h"

/**
 * 숫자인경우
 * 첫번째 문자가 - 이면서 뒤에 '\0'이 오기 전까지 모두 숫자인경우
 */
int		atoi_check(char *str_arg)
{
	int			i;

	if (ft_isdigit(str_arg[0]) || str_arg[0] == '-')
	{
		if ((str_arg[0]) == '-')
			i = 1;
		else
			i = 0;
		while (str_arg[i] != '\0')
		{
			if (!ft_isdigit(str_arg[i]))
				return (-1);
			i++;
		}
	}
	else
		return (-1);
	return (i);
}

int		str_to_list(t_stack **lst, char **str, int size)
{
	t_stack		*tmp;
	int			*int_arr;
	int			i;
	long long	int_tmp;

	if (!(int_arr = (int *)malloc(sizeof(int) * size)))
		return (-1);
	i = 0;
	while (str[i] != NULL)
	{
		if (atoi_check(str[i]) == -1)
			return (-1);
		int_tmp = ft_atoi(str[i]);
		if (int_tmp > 2147483647 || int_tmp < -2147483648)
			return (-1);
		int_arr[i] = int_tmp;
		if (double_check(int_arr, i, int_arr[i]) == -1)
			return (-1);
		tmp = ft_new(int_arr[i]);
		ft_add(lst, tmp);
		i++;
	}
	free(int_arr);
	return (i);
}

void	valid_arg(char *argv)
{
	int		i;

	i = 0;
	if (argv[0] == '\0')
		exit(0);
	while (argv[i + 1] != '\0')
	{
		if (argv[i] == ' ' && argv[i + 1] == ' ')
		{
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		i++;
	}
}

int		input_list(t_stack **a, char **argv, int argc)
{
	char		**str_tmp;
	int			i;

	if (argc > 2)
	{
		if (str_to_list(a, &argv[1], argc - 1) == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
	}
	else if (argc == 2)
	{
		valid_arg(argv[1]);
		str_tmp = ft_split(argv[1], ' ');
		i = str_to_list(a, str_tmp, ft_strlen_2(str_tmp));
		if (i == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		argc += (i - 1);
		dptr_free(str_tmp);
	}
	return (argc);
}
