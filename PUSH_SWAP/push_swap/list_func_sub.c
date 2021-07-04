/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:29:37 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 19:33:54 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_delone_free(t_stack **lst)
{
	t_stack		*tmp1;
	t_stack		*tmp2;

	if (lst == NULL || *lst == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		free(*lst);
		*lst = NULL;
		return ;
	}
	if ((*lst)->next == (*lst)->prev)
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
