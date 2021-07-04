/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:29:32 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 19:58:44 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new(int content)
{
	t_stack		*node;

	if (!(node = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->content = content;
	return (node);
}

void	ft_add(t_stack **lst, t_stack *new1)
{
	t_stack		*last;

	last = NULL;
	if (lst == NULL || new1 == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new1;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
		return ;
	}
	if ((*lst)->prev == NULL)
	{
		(*lst)->next = new1;
		new1->prev = *lst;
	}
	else
	{
		last = (*lst)->prev;
		new1->prev = last;
		last->next = new1;
	}
	(*lst)->prev = new1;
	new1->next = *lst;
}

int		ft_listsize(t_stack *lst)
{
	t_stack		*tmp;
	int			cnt;

	tmp = lst;
	cnt = 0;
	if (lst == NULL)
		return (0);
	while (tmp->next != NULL && tmp->next != lst)
	{
		cnt++;
		tmp = tmp->next;
	}
	cnt++;
	return (cnt);
}

void	ft_delone(t_stack **lst)
{
	t_stack		*tmp1;
	t_stack		*tmp2;

	if (lst == NULL || *lst == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		*lst = NULL;
		return ;
	}
	if ((*lst)->next == (*lst)->prev)
	{
		tmp1 = (*lst)->next;
		tmp1->next = NULL;
		tmp1->prev = NULL;
		*lst = tmp1;
	}
	else
	{
		tmp1 = (*lst)->prev;
		tmp2 = (*lst)->next;
		tmp1->next = tmp2;
		tmp2->prev = tmp1;
		*lst = tmp2;
	}
}
