/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:27:05 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 20:18:33 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dptr_free(char **dptr)
{
	int		i;

	i = 0;
	while (dptr[i])
	{
		free(dptr[i]);
		dptr[i] = 0;
		i++;
	}
	free(dptr);
	dptr = 0;
}

int		ft_strlen_2(char **str)
{
	int		result;

	result = 0;
	while (str[result] != NULL)
		result++;
	return (result);
}

int		double_check(int *int_arr, int len, int value)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (int_arr[i] == value)
			return (-1);
		i++;
	}
	return (i);
}

int		check_sort(t_stack *lst, int len)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	tmp = lst;
	while (tmp->next != NULL && tmp->next != lst)
	{
		if ((tmp->content) > (tmp->next->content))
			return (-1);
		tmp = tmp->next;
		i++;
	}
	if (len != ++i)
		return (-1);
	return (i);
}
