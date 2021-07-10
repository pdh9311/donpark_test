/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 07:52:11 by donpark           #+#    #+#             */
/*   Updated: 2021/01/28 09:12:55 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*curr;
	t_list	*add_node;

	if (!lst || !f)
		return (0);
	if (!(first_node = ft_lstnew(f(lst->content))))
		return (0);
	curr = first_node;
	lst = lst->next;
	while (lst)
	{
		if (!(add_node = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&first_node, del);
			return (0);
		}
		curr->next = add_node;
		curr = add_node;
		lst = lst->next;
	}
	return (first_node);
}
