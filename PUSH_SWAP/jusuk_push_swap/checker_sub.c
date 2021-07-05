#include "push_swap.h"

int		sort_sub(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp("pa", line, 3) == 0)
		push_list_checker(a, b);
	else if (ft_strncmp("pb", line, 3) == 0)
		push_list_checker(b, a);
	else if (ft_strncmp("ra", line, 3) == 0)
		rotate_list_checker(a, -1);
	else if (ft_strncmp("rb", line, 3) == 0)
		rotate_list_checker(b, -1);
	else if (ft_strncmp("rr", line, 3) == 0)
	{
		rotate_list_checker(a, -1);
		rotate_list_checker(b, -1);
	}
	else if (ft_strncmp("rra", line, 3) == 0)
		rotate_list_checker(a, 1);
	else if (ft_strncmp("rrb", line, 3) == 0)
		rotate_list_checker(b, 1);
	else if (ft_strncmp("rrr", line, 3) == 0)
	{
		rotate_list_checker(a, 1);
		rotate_list_checker(b, 1);
	}
	else
		return (-1);
	return (0);
}

int		sort(t_stack **a, t_stack **b, char *line)
{
	if (ft_strncmp("sa", line, 3) == 0)
		swap_list_checker(a);
	else if (ft_strncmp("sb", line, 3) == 0)
		swap_list_checker(b);
	else if (ft_strncmp("ss", line, 3) == 0)
	{
		swap_list_checker(a);
		swap_list_checker(b);
	}
	else
		return (sort_sub(a, b, line));
	return (0);
}

void	swap_list_checker(t_stack **lst)
{
	int		tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
}

// lst2 에서 lst1으로 push
void	push_list_checker(t_stack **lst1, t_stack **lst2)
{
	t_stack	*tmp;

	if (lst2 == NULL || *lst2 == NULL)
		return ;
	tmp = *lst2;
	ft_delone(lst2);
	ft_add(lst1, tmp);	// list의 뒤에 추가 하기 때문에
	if ((*lst1)->prev != NULL && (*lst1)->next != NULL)		// 초기위치를 추가한 위치로 옮겨준다
		*lst1 = (*lst1)->prev;
}

// direction 1 이면 rra rrb
void	rotate_list_checker(t_stack **lst, int direction)
{
	if (*lst == NULL || (*lst)->prev == NULL || (*lst)->next == NULL)
		return ;
	if (direction == 1)
		*lst = (*lst)->prev;
	else
		*lst = (*lst)->next;
}
