#include "push_swap.h"

/**
 * CASE5 : 1 3 2 < < > sb pa sb pa pa
 * CASE6 : 1 2 3 < < < rb sb pa pa rrb pa
 */
void		sort_23_ba_fix_sub3(t_stack **dst, t_stack **src, int *buf, int *flag)
{
	if ((*src)->content < (*src)->next->content &&
		(*src)->content < (*src)->next->next->content &&
		(*src)->next->content > (*src)->next->next->content)
	{
		swap_list(src, 'b', buf);
		push_list(dst, src, 'a', buf);
		swap_list(src, 'b', buf);
		push_list(dst, src, 'a', buf);
		push_list(dst, src, 'a', buf);
		*flag = 1;
	}
	else if ((*src)->content < (*src)->next->content &&
			(*src)->content < (*src)->next->next->content &&
			(*src)->next->content < (*src)->next->next->content)
	{
		rotate_list(src, -1, 'b', buf);
		swap_list(src, 'b', buf);
		push_list(dst, src, 'a', buf);
		push_list(dst, src, 'a', buf);
		rotate_list(src, 1, 'b', buf);
		push_list(dst, src, 'a', buf);
		*flag = 1;
	}
}

/**
 * CASE3 : 2 3 1 < > > sb pa pa pa
 * CASE4 : 2 1 3 > < < rb sb pa rrb pa pa
 */
void		sort_23_ba_fix_sub2(t_stack **dst, t_stack **src, int *buf, int *flag)
{
	if ((*src)->content < (*src)->next->content &&
		(*src)->content > (*src)->next->next->content &&
		(*src)->next->content > (*src)->next->next->content)
	{
		swap_list(src, 'b', buf);
		push_list(dst, src, 'a', buf);
		push_list(dst, src, 'a', buf);
		push_list(dst, src, 'a', buf);
		*flag = 1;
	}
	else if ((*src)->content > (*src)->next->content &&
			(*src)->content < (*src)->next->next->content &&
			(*src)->next->content < (*src)->next->next->content)
	{
		rotate_list(src, -1, 'b', buf);
		swap_list(src, 'b', buf);
		push_list(dst, src, 'a', buf);
		rotate_list(src, 1, 'b', buf);
		push_list(dst, src, 'a', buf);
		push_list(dst, src, 'a', buf);
		*flag = 1;
	}
}

/**
 * CASE1 : 3 2 1 > > > pa pa pa
 * CASE2 : 3 1 2 > > < pa sb pa pa
 */
void		sort_23_ba_fix_sub1(t_stack **dst, t_stack **src, int *buf, int *flag)
{
	if ((*src)->content > (*src)->next->content &&
		(*src)->content > (*src)->next->next->content &&
		(*src)->next->content > (*src)->next->next->content)
	{
		push_list(dst, src, 'a', buf);
		push_list(dst, src, 'a', buf);
		push_list(dst, src, 'a', buf);
		*flag = 1;
	}
	else if ((*src)->content > (*src)->next->content &&
			(*src)->content > (*src)->next->next->content &&
			(*src)->next->content < (*src)->next->next->content)
	{
		push_list(dst, src, 'a', buf);
		swap_list(src, 'b', buf);
		push_list(dst, src, 'a', buf);
		push_list(dst, src, 'a', buf);
		*flag = 1;
	}
}

/**
 * CASE1 : 3 2 1 > > > pa pa pa
 * CASE2 : 3 1 2 > > < pa sb pa pa
 * CASE3 : 2 3 1 < > > sb pa pa pa
 * CASE4 : 2 1 3 > < < rb sb pa rrb pa pa
 * CASE5 : 1 3 2 < < > sb pa sb pa pa
 * CASE6 : 1 2 3 < < < rb sb pa pa rrb pa
 *
 * ex) B | 4 5 3 1 2 에서 4 5 3을 정렬된 상태로 A로 보내기 위해서 CASE3 사용
 * sb	| 5 4 3 1 2
 * pa	| 4 3 1 2
 * pa	| 3 1 2
 * pa	| 1 2
 * 1 2의 위치를 고정시킨 상태에서 3 4 5 만 정렬된 상태로 A로 넘겨주었다.
 */
void		sort_23_ba_fix_sub(t_stack **dst, t_stack **src, int *buf)
{
	int			flag;

	flag = 0;
	if (flag == 0)
		sort_23_ba_fix_sub1(dst, src, buf, &flag);
	if (flag == 0)
		sort_23_ba_fix_sub2(dst, src, buf, &flag);
	if (flag == 0)
		sort_23_ba_fix_sub3(dst, src, buf, &flag);
}

void		sort_23_ba_fix(t_stack **dst, t_stack **src, int len, int *buf)
{
	if (len == 3)
		sort_23_ba_fix_sub(dst, src, buf);
	else if (len == 2)
	{
		if ((*src)->content > (*src)->next->content)
		{
			push_list(dst, src, 'a', buf);
			push_list(dst, src, 'a', buf);
		}
		else
		{
			swap_list(src, 'b', buf);
			push_list(dst, src, 'a', buf);
			push_list(dst, src, 'a', buf);
		}
	}
	else
		push_list(dst, src, 'a', buf);
}
