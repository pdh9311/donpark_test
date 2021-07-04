/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_23_ba_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:27:16 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 19:34:25 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_23_ba_fix_sub3(t_stack **dst, t_stack **src, int *buf, int *flag)
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

void	sort_23_ba_fix_sub2(t_stack **dst, t_stack **src, int *buf, int *flag)
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

void	sort_23_ba_fix_sub1(t_stack **dst, t_stack **src, int *buf, int *flag)
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

void	sort_23_ba_fix_sub(t_stack **dst, t_stack **src, int *buf)
{
	int		flag;

	flag = 0;
	if (flag == 0)
		sort_23_ba_fix_sub1(dst, src, buf, &flag);
	if (flag == 0)
		sort_23_ba_fix_sub2(dst, src, buf, &flag);
	if (flag == 0)
		sort_23_ba_fix_sub3(dst, src, buf, &flag);
}

void	sort_23_ba_fix(t_stack **dst, t_stack **src, int len, int *buf)
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
