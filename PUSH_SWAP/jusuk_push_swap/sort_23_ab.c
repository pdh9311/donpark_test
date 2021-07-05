#include "push_swap.h"

/**
 * 1 2 3 (alreacy sorted)
 * CASE1 : 1 3 2 < < > ra sa rra
 * CASE2 : 2 3 1 < > > ra sa rra sa
 * CASE3 : 2 1 3 > < < sa
 * CASE4 : 3 1 2 > > < sa ra sa rra
 * CASE5 : 3 2 1 > > > sa ra sa rra sa
 * ex) A | 4 5 3 1 2 에서 4 5 3을 정렬하기위해서 CASE2 사용
 * ra	| 5 3 1 2 4
 * sa	| 3 5 1 2 4
 * rra	| 4 3 5 1 2
 * sa	| 3 4 5 1 2
 * 1 2의 위치를 고정시킨 상태에서 3 4 5 만 정렬 시켰다.
 */
void		sort_23_ab_fix_sub(t_stack **lst, int *buf)
{
	if ((*lst)->content > (*lst)->next->content &&
		(*lst)->content < (*lst)->next->next->content &&
		(*lst)->next->content < (*lst)->next->next->content)
		swap_list(lst, 'a', buf);
	else if ((*lst)->content > (*lst)->next->content &&
			(*lst)->content > (*lst)->next->next->content &&
			(*lst)->next->content < (*lst)->next->next->content)
	{
		swap_list(lst, 'a', buf);
		rotate_list(lst, -1, 'a', buf);
		swap_list(lst, 'a', buf);
		rotate_list(lst, 1, 'a', buf);
	}
	else if ((*lst)->content > (*lst)->next->content &&
			(*lst)->content > (*lst)->next->next->content &&
			(*lst)->next->content > (*lst)->next->next->content)
	{
		swap_list(lst, 'a', buf);
		rotate_list(lst, -1, 'a', buf);
		swap_list(lst, 'a', buf);
		rotate_list(lst, 1, 'a', buf);
		swap_list(lst, 'a', buf);
	}
}

void		sort_23_ab_fix(t_stack **lst, int len, int *buf)
{
	if (len == 3)
	{
		if ((*lst)->content < (*lst)->next->content &&
			(*lst)->content < (*lst)->next->next->content &&
			(*lst)->next->content > (*lst)->next->next->content)
		{
			rotate_list(lst, -1, 'a', buf);
			swap_list(lst, 'a', buf);
			rotate_list(lst, 1, 'a', buf);
		}
		else if ((*lst)->content < (*lst)->next->content &&
				(*lst)->content > (*lst)->next->next->content &&
				(*lst)->next->content > (*lst)->next->next->content)
		{
			rotate_list(lst, -1, 'a', buf);
			swap_list(lst, 'a', buf);
			rotate_list(lst, 1, 'a', buf);
			swap_list(lst, 'a', buf);
		}
		sort_23_ab_fix_sub(lst, buf);
	}
	else if (len == 2 && (*lst)->content > (*lst)->next->content)
		swap_list(lst, 'a', buf);
}

/**
 * 1 2 3 (alreacy sorted)
 * CASE1 : 1 3 2 < < > (rra, sa) or (sa, ra)
 * CASE2 : 2 1 3 > < < sa
 * CASE3 : 2 3 1 < > > rra
 * CASE4 : 3 1 2 > > < ra
 * CASE5 : 3 2 1 > > > sa rra
 */
void		sort_23_ab_sub(t_stack **lst, int *buf)
{
	if ((*lst)->content < (*lst)->next->content &&
		(*lst)->content > (*lst)->next->next->content &&
		(*lst)->next->content > (*lst)->next->next->content)
		rotate_list(lst, 1, 'a', buf);
	else if ((*lst)->content > (*lst)->next->content &&
			(*lst)->content > (*lst)->next->next->content &&
			(*lst)->next->content < (*lst)->next->next->content)
		rotate_list(lst, -1, 'a', buf);
	else if ((*lst)->content > (*lst)->next->content &&
			(*lst)->content > (*lst)->next->next->content &&
			(*lst)->next->content > (*lst)->next->next->content)
	{
		swap_list(lst, 'a', buf);
		rotate_list(lst, 1, 'a', buf);
	}
}

void		sort_23_ab(t_stack **lst, int len, int *buf)
{
	if (len == 3)
	{
		if ((*lst)->content < (*lst)->next->content &&
			(*lst)->content < (*lst)->next->next->content &&
			(*lst)->next->content > (*lst)->next->next->content)
		{
			rotate_list(lst, 1, 'a', buf);
			swap_list(lst, 'a', buf);
		}
		else if ((*lst)->content > (*lst)->next->content &&
				(*lst)->content < (*lst)->next->next->content &&
				(*lst)->next->content < (*lst)->next->next->content)
			swap_list(lst, 'a', buf);
		sort_23_ab_sub(lst, buf);
	}
	else if (len == 2 && (*lst)->content > (*lst)->next->content)
		swap_list(lst, 'a', buf);
}
