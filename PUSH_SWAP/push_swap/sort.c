/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:27:07 by donpark           #+#    #+#             */
/*   Updated: 2021/07/05 18:06:50 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		pivot_condition_ba(a, b, &tmp, buf);
	reverse_rotate_ba(b, tmp, 'b', buf);
	push_swap_sort_ab(a, b, tmp.len_a - tmp.back_a, buf);
	reverse_rotate_ba(a, tmp, 'a', buf);
	push_swap_sort_ab(a, b, tmp.back_a, buf);
	push_swap_sort_ba(b, a, tmp.len_b, buf);
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
		pivot_condition_ab(a, b, &tmp, buf);
	reverse_rotate_ab(a, b, tmp, buf);
	push_swap_sort_ab(a, b, tmp.len_a, buf);
	push_swap_sort_ba(b, a, tmp.back_b, buf);
	push_swap_sort_ba(b, a, tmp.len_b - tmp.back_b, buf);
}

void	push_swap_sort_45_sub(t_stack **a, t_stack **b, int index, int *buf)
{
	int				len;
	int				i;

	i = 0;
	len = ft_listsize(*a);
	if (len - index == 0 || len - index == 1)
	{
		if (len - index == 1)
			rotate_list(a, 1, 'a', buf);
		push_list(a, b, 'a', buf);
		rotate_list(a, -1, 'a', buf);
		if (len - index == 1)
			rotate_list(a, -1, 'a', buf);
	}
	else
	{
		while (i++ < index - 1)
			rotate_list(a, -1, 'a', buf);
		push_list(a, b, 'a', buf);
		if (index > 0)
			swap_list(a, 'a', buf);
		while (--i)
			rotate_list(a, 1, 'a', buf);
	}
}

void	push_swap_sort_45(t_stack **a, t_stack **b, int len, int *buf)
{
	t_stack			*tmp;
	int				num_pa;
	int				tmp_int;
	int				index;

	num_pa = len - 3;
	while (--len >= 3)
		push_list(b, a, 'b', buf);
	sort_23_ab(a, 3, buf);
	len = 0;
	while (num_pa--)
	{
		tmp = *a;
		index = 0;
		tmp_int = 0;
		while (tmp_int++ < 3 + len)
		{
			if ((*b)->content < tmp->content)
				break ;
			tmp = tmp->next;
			index++;
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
