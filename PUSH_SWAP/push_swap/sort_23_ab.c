/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_23_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:28:57 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 19:29:12 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
