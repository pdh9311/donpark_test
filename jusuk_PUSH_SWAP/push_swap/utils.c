#include "push_swap.h"

void	dptr_free(char **dptr)
{
	int		i;

	i = 0;
	while (dptr[i])
	{
		free(dptr[i]);
		dptr[i] = 0;
		i++;
	}
	free(dptr);
	dptr = 0;
}

int		ft_strlen_2(char **str)
{
	int		result;

	result = 0;
	while (str[result] != NULL)
		result++;
	return (result);
}

int		double_check(int *int_arr, int len, int value)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (int_arr[i] == value)
			return (-1);
		i++;
	}
	return (i);
}

// 정렬되어 있는지 확인
int		check_sort(t_stack *lst, int len)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	tmp = lst;
	while (tmp->next != NULL && tmp->next != lst)
	{
		if ((tmp->content) > (tmp->next->content))
			return (-1);
		tmp = tmp->next;
		i++;
	}
	if (len != ++i)
		return (-1);
	return (i);
}
/*
void	test_stack_print(t_stack *a, t_stack *b)
{
	printf("[a] ");
	test_print_dlst(a);
	printf("[b] ");
	if (b != NULL)
		test_print_dlst(b);
}

void	test_print_dlst(t_stack *lst)
{
	t_stack		*tmp;

	if (lst == NULL)
		return ;
	tmp = lst;
	printf("content: ");
	while (tmp->next != NULL && tmp->next != lst)
	{
		printf("(%d)  ", tmp->content);
		tmp = tmp->next;
	}
	printf("(%d)\n", tmp->content);
}
*/
