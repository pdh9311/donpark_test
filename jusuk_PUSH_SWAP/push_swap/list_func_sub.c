#include "push_swap.h"

void	del2(t_stack **lst, t_stack **tmp1)
{
	*tmp1 = (*lst)->next;
	(*tmp1)->prev = NULL;
	(*tmp1)->next = NULL;
}

void	delelse(t_stack **lst, t_stack **tmp1, t_stack **tmp2)
{
	*tmp1 = (*lst)->prev;
	*tmp2 = (*lst)->next;
	(*tmp1)->next = *tmp2;
	(*tmp2)->prev = *tmp1;
}

// Delete list's front node in free
void	ft_delone_free(t_stack **lst)
{
	t_stack		*tmp1;
	t_stack		*tmp2;

	if (lst == NULL || *lst == NULL)
		return ;
	if ((*lst)->next == NULL)			// 1개인 경우
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	if ((*lst)->next == (*lst)->prev)	//  2개만 있는 경우 lst의 맨 앞을 제거
	{
		del2(lst, &tmp1);
		free(*lst);
		*lst = tmp1;
	}
	else
	{
		delelse(lst, &tmp1, &tmp2);
		free(*lst);
		*lst = tmp2;
	}
}

void	ft_delall_free(t_stack **lst, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		ft_delone_free(lst);
		i++;
	}
}

