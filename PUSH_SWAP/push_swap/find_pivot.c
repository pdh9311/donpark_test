/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:29:40 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 19:31:05 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		swap_arr(int *arr, int index_1, int index_2)
{
	int			tmp;

	tmp = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = tmp;
}

void		ft_quick_sort(int *arr, int left, int right)
{
	int	i;
	int	j;
	int	pivot;

	i = left;
	j = right;
	pivot = arr[(i + j) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
			swap_arr(arr, i++, j--);
	}
	if (left < j)
		ft_quick_sort(arr, left, j);
	if (i < right)
		ft_quick_sort(arr, i, right);
}

t_pivot		find_pivot(t_stack **lst, int len)
{
	t_pivot		result;
	t_stack		*tmp;
	int			*arr;
	int			i;

	tmp = *lst;
	i = 0;
	if (!(arr = (int *)malloc(sizeof(int) * len)))
		exit(0);
	while (i < len)
	{
		arr[i++] = tmp->content;
		tmp = tmp->next;
	}
	ft_quick_sort(arr, 0, len - 1);
	result.pivot_l = arr[len / 3];
	result.pivot_h = arr[len * 2 / 3];
	free(arr);
	return (result);
}
