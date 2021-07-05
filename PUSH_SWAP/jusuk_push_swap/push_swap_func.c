#include "push_swap.h"
// rra, rrb
void	reverse_rotate_ba(t_stack **lst, t_tmp tmp, char stack, int *buf)
{
	int		len;
	int		stack_size;

	stack_size = ft_listsize(*lst);
	if (stack == 'a')
	{
		len = tmp.back_a;
		while (stack_size > tmp.back_a && len--)
			rotate_list(lst, 1, stack, buf);
	}
	else if (stack == 'b')
	{
		len = tmp.len_b;
		while (stack_size > tmp.len_b && len--)
			rotate_list(lst, 1, stack, buf);
	}
}

void	reverse_rotate_ab(t_stack **a, t_stack **b, t_tmp tmp, int *buf)
{
	t_stack		**stack_tmp;
	char		stack;
	int			len_1;
	int			len_2;
	int			len_tmp;

	len_1 = tmp.back_b;		// 중간 부분
	len_2 = tmp.len_a;		// 큰 부분
	stack = 'b';
	stack_tmp = b;
	if (tmp.len_a > tmp.back_b)	// 큰 부분이 중간 부분 보다 더 많다면
	{
		len_1 = tmp.len_a;		// 큰 부분
		len_2 = tmp.back_b;		// 중간 부분
		stack = 'a';
		stack_tmp = a;
	}
	len_tmp = len_1 - len_2;
	while (len_2--)
	{
		rotate_list(a, 1, 'a', buf);
		rotate_list(b, 1, 'b', buf);
	}
	while (len_tmp--)
		rotate_list(stack_tmp, 1, stack, buf);
}

void	swap_list(t_stack **lst, char stack, int *buf)
{
	int		tmp;

	if (lst == NULL || *lst == NULL)		// lst == NULL 추가
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
	if (stack == 'a')
		print_instructions(buf, "sa\n");
	else
		print_instructions(buf, "sb\n");
}

// lst2에서 lst1로 push
void	push_list(t_stack **lst1, t_stack **lst2, char stack, int *buf)
{
	t_stack		*tmp;

	if (lst2 == NULL || *lst2 == NULL)
		return ;
	tmp = *lst2;
	ft_delone(lst2);
	ft_add(lst1, tmp);
	if ((*lst1)->prev != NULL && (*lst1)->next != NULL)
		*lst1 = (*lst1)->prev;
	if (stack == 'a')
		print_instructions(buf, "pa\n");
	else
		print_instructions(buf, "pb\n");
}

/**
 * [ rotate ]	-1
 * 			A	A'
 * top		1	2
 * 			2	3
 * 			3	4
 * bottom	4	1
 *****************
 * [ rrotate ]	1
 * 			A	A'
 * top		1	4
 * 			2	1
 * 			3	2
 * bottom	4	3
 */
void	rotate_list(t_stack **lst, int direction, char stack, int *buf)
{
	if (*lst == NULL || (*lst)->prev == NULL || (*lst)->next == NULL)
		return ;
	if (direction == 1)	// direction 이 1 인 경우 reverse rotation
	{
		*lst = (*lst)->prev;
		if (stack == 'a')
			print_instructions(buf, "rra\n");
		else
			print_instructions(buf, "rrb\n");
	}
	else
	{
		*lst = (*lst)->next;
		if (stack == 'a')
			print_instructions(buf, "ra\n");
		else
			print_instructions(buf, "rb\n");
	}
}
