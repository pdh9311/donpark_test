#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
// # include <stdio.h>

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

typedef struct	s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				content;
	int				rank;
}				t_stack;

typedef struct	s_pivot
{
	int				pivot_l;
	int				pivot_h;
}				t_pivot;

typedef struct	s_tmp
{
	t_pivot			pivot;
	int				len_a;
	int				len_b;
	int				back_a;
	int				back_b;
}				t_tmp;

void		test_stack_print(t_stack *a, t_stack *b);
void		test_print_dlst(t_stack *lst);
//////////////////////////////////////////////////////////////////////////////
t_stack		*ft_new(int content);
void		ft_add(t_stack **lst, t_stack *new);
int			ft_listsize(t_stack *lst);
void		ft_delone(t_stack **lst);
void		del2(t_stack **lst, t_stack **tmp1);
void		delelse(t_stack **lst, t_stack **tmp1, t_stack **tmp2);
void		ft_delone_free(t_stack **lst);
void		ft_delall_free(t_stack **lst, int size);
//////////////////////////////////////////////////////////////////////////////
void		dptr_free(char **dptr);
int			ft_strlen_2(char **str);
int			double_check(int *int_arr, int len, int value);
int			atoi_check(char *str_arg);
int			str_to_stack(t_stack **lst, char **str, int size);
void		valid_arg(char *argv);
int			input_list(t_stack **a, char **argv, int argc);
//////////////////////////////////////////////////////////////////////////////
void		swap_arr(int *arr, int index_1, int index_2);
// void		ft_quick_sort(int *arr, int len);
void		ft_quick_sort(int *arr, int left, int right);
// void		ft_quick_sort(int *arr, int left, int right, int len);
t_pivot		find_pivot(t_stack **lst, int len);
//////////////////////////////////////////////////////////////////////////////
void		recursive_0123_ab(t_stack **a, int len, int *buf);
void		recursive_0123_ba(t_stack **a, t_stack **b, int len, int *buf);
void		pivot_condition_ba(t_stack **a, t_stack **b, t_tmp *tmp, int *buf);
void		pivot_condition_ab(t_stack **a, t_stack **b, t_tmp *tmp, int *buf);
void		init_struct_tmp(t_tmp *input);
//////////////////////////////////////////////////////////////////////////////
void		input_str(char **tmp);
void		print_swap(char **tmp, int *buf, char *str);
void		print_rotate(char **tmp, int *buf, char *str);
void		print_reverse_rotate(char **tmp, int *buf, char *str);
void		print_instructions(int *buf, char *str);
//////////////////////////////////////////////////////////////////////////////
void		sort_23_ba_fix_sub3(t_stack **dst, t_stack **src, int *buf, int *flag);
void		sort_23_ba_fix_sub2(t_stack **dst, t_stack **src, int *buf, int *flag);
void		sort_23_ba_fix_sub1(t_stack **dst, t_stack **src, int *buf, int *flag);
void		sort_23_ba_fix_sub(t_stack **dst, t_stack **src, int *buf);
void		sort_23_ba_fix(t_stack **dst, t_stack **src, int len, int *buf);
//////////////////////////////////////////////////////////////////////////////
void		sort_23_ba_sub3(t_stack **dst, t_stack **src, int *buf, int *flag);
void		sort_23_ba_sub2(t_stack **dst, t_stack **src, int *buf, int *flag);
void		sort_23_ba_sub1(t_stack **dst, t_stack **src, int *buf, int *flag);
void		sort_23_ba_sub(t_stack **dst, t_stack **src, int *buf);
void		sort_23_ba(t_stack **dst, t_stack **src, int len, int *buf);
//////////////////////////////////////////////////////////////////////////////
void		sort_23_ab_fix_sub(t_stack **lst, int *buf);
void		sort_23_ab_fix(t_stack **lst, int len, int *buf);
void		sort_23_ab_sub(t_stack **lst, int *buf);
void		sort_23_ab(t_stack **lst, int len, int *buf);
//////////////////////////////////////////////////////////////////////////////
void		push_swap_sort_ba(t_stack **b, t_stack **a, int len, int *buf);
void		push_swap_sort_ab(t_stack **a, t_stack **b, int len, int *buf);
void		push_swap_sort_45_sub(t_stack **a, t_stack **b, int index, int *buf);
void		push_swap_sort_45(t_stack **a, t_stack **b, int len, int *buf);
void		push_swap_sort(t_stack **a, t_stack **b, int len, int *buf);
int			check_sort(t_stack *lst, int len);
//////////////////////////////////////////////////////////////////////////////
void		reverse_rotate_ba(t_stack **lst, t_tmp tmp, char stack, int *buf);
void		reverse_rotate_ab(t_stack **a, t_stack **b, t_tmp tmp, int *buf);
void		swap_list(t_stack **lst, char stack, int *buf);
void		push_list(t_stack **lst1, t_stack **lst2, char stack, int *buf);
void		rotate_list(t_stack **lst, int direction, char stack, int *buf);
//////////////////////////////////////////////////////////////////////////////
void		rotate_list_checker(t_stack **lst, int direction);
void		push_list_checker(t_stack **lst1, t_stack **lst2);
void		swap_list_checker(t_stack **lst);
int			sort_sub(t_stack **a, t_stack **b, char *line);
int			sort(t_stack **a, t_stack **b, char *line);
int			get_instructions(t_stack **a, t_stack **b);
//////////////////////////////////////////////////////////////////////////////
#endif
