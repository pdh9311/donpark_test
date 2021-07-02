#include "push_swap.h"

int			get_instructions(t_stack **a, t_stack **b)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp("Error", line, 5) == 0)
			return (-1);
		else if (line != NULL)
			if (sort(a, b, line) == -1)
				return (-1);
		free(line);
	}
	free(line);
	return (0);
}

int			main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (input_list(&a, argv, argc) == -1)
		return (0);
	len = ft_listsize(a);
	if (get_instructions(&a, &b) == -1)
	{
		ft_delall_free(&a, len);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (check_sort(a, len) == -1)
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	ft_delall_free(&a, len);
	return (0);
}
