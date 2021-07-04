/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donpark <donpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 19:29:21 by donpark           #+#    #+#             */
/*   Updated: 2021/07/04 19:32:10 by donpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_stack		*a;
	t_stack		*b;
	char		*print[12];
	int			*buf;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!(buf = (int *)malloc(sizeof(int))))
		return (0);
	*buf = 0;
	if ((argc = input_list(&a, argv, argc)) == -1)
		return (0);
	if (check_sort(a, argc - 1) != -1)
		return (0);
	push_swap_sort(&a, &b, argc - 1, buf);
	input_str(print);
	if (*buf != 0)
		ft_putstr_fd(print[*buf], 1);
	ft_delall_free(&a, argc - 1);
	free(buf);
	return (0);
}
