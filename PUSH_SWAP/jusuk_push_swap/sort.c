#include "push_swap.h"

void	push_swap_sort_ba(t_stack **b, t_stack **a, int len, int *buf)
{
	t_tmp			tmp;

	if (len == 0 || len == 1 || len == 2 || len == 3)
	{
		recursive_0123_ba(a, b, len, buf);
		return ;
	}
	init_struct_tmp(&tmp);
	tmp.pivot = find_pivot(b, len);
	while (*b != NULL && len--)
		pivot_condition_ba(a, b, &tmp, buf);	// B의 pivot을 기준으로 큰 부분, 중간 부분, 작은 부분을 나누어 준다.
	reverse_rotate_ba(b, tmp, 'b', buf);	// B의 작은 부분을 앞으로 가져온다.
	push_swap_sort_ab(a, b, tmp.len_a - tmp.back_a, buf);	// A의 큰 부분을 다시 정렬
	reverse_rotate_ba(a, tmp, 'a', buf);		// A의 중간 부분을 앞으로 가져온다.
	push_swap_sort_ab(a, b, tmp.back_a, buf);	// A의 큰 부분이 정렬될때까지 재귀호출하면서 A를 정렬
	push_swap_sort_ba(b, a, tmp.len_b, buf);	// B의 작은 부분을 정렬해서 A로 push
}

void	push_swap_sort_ab(t_stack **a, t_stack **b, int len, int *buf)
{
	t_tmp		tmp;

	if (len == 0 || len == 1 || len == 2 || len == 3)
	{
		recursive_0123_ab(a, len, buf);
		return ;
	}
	init_struct_tmp(&tmp);
	tmp.pivot = find_pivot(a, len);
	while (*a != NULL && len--)
		pivot_condition_ab(a, b, &tmp, buf);	// A의 pivot을 기준으로 큰 부분, 중간 부분, 작은 부분을 나누어 준다.
	reverse_rotate_ab(a, b, tmp, buf);			// B에 중간 부분을 앞으로 가져온다.
	push_swap_sort_ab(a, b, tmp.len_a, buf);	// A의 큰 부분이 정렬될때까지 재귀호출하면서 A를 정렬
	push_swap_sort_ba(b, a, tmp.back_b, buf);	// A가 정렬된 순간부터 B의 중간 부분을 역정렬해서 A에 push하여 정렬한다.
	push_swap_sort_ba(b, a, tmp.len_b - tmp.back_b, buf);	// B의 작은 부분을 정렬해서 A로 push
}

void	push_swap_sort_45_sub(t_stack **a, t_stack **b, int index, int *buf)
{
	int				len;
	int				i;

	i = 0;
	len = ft_listsize(*a);
	if (len - index == 0 || len - index == 1)	// 마지막이나 마지막 앞에 삽입 될 경우
	{
		if (len - index == 1)	// len - index 가 1인 경우 마지막 앞에 삽입되는 경우이므로 rra pa ra ra
			rotate_list(a, 1, 'a', buf);
		push_list(a, b, 'a', buf);	// len - index 가 0인 경우 마지막에 삽입되는 경우이므로 pa ra
		rotate_list(a, -1, 'a', buf);
		if (len - index == 1)
			rotate_list(a, -1, 'a', buf);
	}
	else	// 1, 2 번째 또는 3 번째에 들어갈 경우
	{
		while (i++ < index - 1)	// 인자가 5개인데 4개가 정렬된 상태에서 3번째(index=2) 들어갈 경우 ra pa sa rra
			rotate_list(a, -1, 'a', buf);
		push_list(a, b, 'a', buf);	// 1 번째 들어갈 경우 pa
		if (index > 0)
			swap_list(a, 'a', buf);	// 2번째 들어갈 경우 pa sa
		while (--i)
			rotate_list(a, 1, 'a', buf);
	}
}

void	push_swap_sort_45(t_stack **a, t_stack **b, int len, int *buf)
{
	t_stack			*tmp;
	int				num_pb;
	int				tmp_int;
	int				index;

	num_pb = len - 3;
	while (--len >= 3)		// a에 3개만 남기고 b로 push한 다음
		push_list(b, a, 'b', buf);
	sort_23_ab(a, 3, buf);	// a에 3개를 정렬하고
	len = 0;
	while (num_pb--)		// b로 push한 개수만큼 반복하는데
	{
		tmp = *a;
		index = 0;
		tmp_int = 0;
		while (tmp_int++ < 3 + len)		//
		{
			if ((*b)->content < tmp->content)	// a에 있는 값과 앞에서부터 비교하는데 a에 있는 값보다 작으면 스톱
				break ;
			tmp = tmp->next;
			index++;	// a에 있는 값보다 작은 위치의 index값을 알아둔다. (0 <= index <= 4)
		}
		len++;
		push_swap_sort_45_sub(a, b, index, buf);
	}
}

void	push_swap_sort(t_stack **a, t_stack **b, int len, int *buf)
{
	if (len >= 4 && len <= 5)
		push_swap_sort_45(a, b, len, buf);
	else
		push_swap_sort_ab(a, b, len, buf);
}
