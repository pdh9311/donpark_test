/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 05:06:52 by donpark           #+#    #+#             */
/*   Updated: 2021/01/25 12:44:26 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	if (!(node = (t_list *)ft_calloc(1, sizeof(t_list))))
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}
