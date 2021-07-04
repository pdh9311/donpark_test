/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:27:08 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 19:29:17 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recursive_0123_ba(t_stack **a, t_stack **b, int len, int *buf)
{
	if (len == 2 || len == 3)
	{
		if (len == ft_listsize(*b))
			sort_23_ba(a, b, len, buf);
		else
			sort_23_ba_fix(a, b, len, buf);
	}
	else if (len == 1)
		push_list(a, b, 'a', buf);
}

void	recursive_0123_ab(t_stack **a, int len, int *buf)
{
	if (len == 2 || len == 3)
	{
		if (len == ft_listsize(*a))
			sort_23_ab(a, len, buf);
		else
			sort_23_ab_fix(a, len, buf);
	}
}

void	pivot_condition_ba(t_stack **a, t_stack **b, t_tmp *tmp, int *buf)
{
	if (tmp->pivot.pivot_l > (*b)->content)
	{
		rotate_list(b, -1, 'b', buf);
		tmp->len_b++;
	}
	else
	{
		if (tmp->pivot.pivot_h <= (*b)->content)
			push_list(a, b, 'a', buf);
		else if (tmp->pivot.pivot_h > (*b)->content)
		{
			push_list(a, b, 'a', buf);
			rotate_list(a, -1, 'a', buf);
			tmp->back_a++;
		}
		tmp->len_a++;
	}
}

void	pivot_condition_ab(t_stack **a, t_stack **b, t_tmp *tmp, int *buf)
{
	if (tmp->pivot.pivot_h < (*a)->content)
	{
		rotate_list(a, -1, 'a', buf);
		tmp->len_a++;
	}
	else
	{
		if (tmp->pivot.pivot_l >= (*a)->content)
			push_list(b, a, 'b', buf);
		else if (tmp->pivot.pivot_l < (*a)->content)
		{
			push_list(b, a, 'b', buf);
			rotate_list(b, -1, 'b', buf);
			tmp->back_b++;
		}
		tmp->len_b++;
	}
}

void	init_struct_tmp(t_tmp *input)
{
	input->len_a = 0;
	input->len_b = 0;
	input->back_a = 0;
	input->back_b = 0;
}
