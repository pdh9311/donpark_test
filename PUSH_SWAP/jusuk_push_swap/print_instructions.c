#include "push_swap.h"

void	input_str(char **tmp)
{
	tmp[0] = NULL;
	tmp[1] = "sa\n";
	tmp[2] = "sb\n";
	tmp[3] = "ss\n";
	tmp[4] = "pa\n";
	tmp[5] = "pb\n";
	tmp[6] = "ra\n";
	tmp[7] = "rb\n";
	tmp[8] = "rr\n";
	tmp[9] = "rra\n";
	tmp[10] = "rrb\n";
	tmp[11] = "rrr\n";
}

void	print_swap(char **tmp, int *buf, char *str)
{
	if (ft_strncmp("sa", str, 2) == 0)
	{
		if (*buf != 0 && ft_strncmp("sb", tmp[*buf], 2) == 0)
		{
			ft_putstr_fd(tmp[3], 1);
			*buf = 0;
			return ;
		}
		if (*buf != 0)
			ft_putstr_fd(tmp[*buf], 1);
		*buf = 1;
	}
	else if (ft_strncmp("sb", str, 2) == 0)
	{
		if (*buf != 0 && ft_strncmp("sa", tmp[*buf], 2) == 0)
		{
			ft_putstr_fd(tmp[3], 1);
			*buf = 0;
			return ;
		}
		if (*buf != 0)
			ft_putstr_fd(tmp[*buf], 1);
		*buf = 2;
	}
}

void	print_rotate(char **tmp, int *buf, char *str)
{
	if (ft_strncmp("ra", str, 2) == 0)
	{
		if (*buf != 0 && ft_strncmp("rb", tmp[*buf], 2) == 0)
		{
			ft_putstr_fd(tmp[8], 1);
			*buf = 0;
			return ;
		}
		if (*buf != 0)
			ft_putstr_fd(tmp[*buf], 1);
		*buf = 6;
	}
	else if (ft_strncmp("rb", str, 2) == 0)
	{
		if (*buf != 0 && ft_strncmp("ra", tmp[*buf], 2) == 0)
		{
			ft_putstr_fd(tmp[8], 1);
			*buf = 0;
			return ;
		}
		if (*buf != 0)
			ft_putstr_fd(tmp[*buf], 1);
		*buf = 7;
	}
}

void	print_reverse_rotate(char **tmp, int *buf, char *str)
{
	if (ft_strncmp("rra", str, 3) == 0)
	{
		if (*buf != 0 && ft_strncmp("rrb", tmp[*buf], 3) == 0)
		{
			ft_putstr_fd(tmp[11], 1);
			*buf = 0;
			return ;
		}
		if (*buf != 0)
			ft_putstr_fd(tmp[*buf], 1);
		*buf = 9;
	}
	else if (ft_strncmp("rrb", str, 3) == 0)
	{
		if (*buf != 0 && ft_strncmp("rra", tmp[*buf], 3) == 0)
		{
			ft_putstr_fd(tmp[11], 1);
			*buf = 0;
			return ;
		}
		if (*buf != 0)
			ft_putstr_fd(tmp[*buf], 1);
		*buf = 10;
	}
}

void	print_instructions(int *buf, char *str)
{
	char		*tmp[12];

	input_str(tmp);
	if (ft_strncmp("pa", str, 2) == 0)
	{
		if (*buf != 0)
			ft_putstr_fd(tmp[*buf], 1);
		*buf = 4;
	}
	else if (ft_strncmp("pb", str, 2) == 0)
	{
		if (*buf != 0)
			ft_putstr_fd(tmp[*buf], 1);
		*buf = 5;
	}
	else if (ft_strncmp("sa", str, 2) == 0 || ft_strncmp("sb", str, 2) == 0)
		print_swap(tmp, buf, str);
	else if (ft_strncmp("ra", str, 2) == 0 || ft_strncmp("rb", str, 2) == 0)
		print_rotate(tmp, buf, str);
	else if (ft_strncmp("rra", str, 3) == 0 || ft_strncmp("rrb", str, 3) == 0)
		print_reverse_rotate(tmp, buf, str);
}
