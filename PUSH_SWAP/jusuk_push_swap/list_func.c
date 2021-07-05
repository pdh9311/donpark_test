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

// Add to back
void	ft_add(t_stack **lst, t_stack *new)
{
	t_stack		*last;

	last = NULL;
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)				// 비어 있는 경우
	{
		*lst = new;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
		return ;
	}
	if ((*lst)->prev == NULL)		// 처음 1개만 만들어졌을 경우
	{
		(*lst)->next = new;
		new->prev = *lst;
	}
	else
	{
		last = (*lst)->prev;
		new->prev = last;
		last->next = new;
	}
	(*lst)->prev = new;
	new->next = *lst;
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

// Delete list's front node
void	ft_delone(t_stack **lst)
{
	t_stack		*tmp1;
	t_stack		*tmp2;

	if (lst == NULL || *lst == NULL)
		return ;
	if ((*lst)->next == NULL)			// 1개인 경우
	{
		*lst = NULL;
		return ;
	}
	if ((*lst)->next == (*lst)->prev)	//  2개만 있는 경우 lst의 맨 앞을 제거
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

/*	test push_list
void			push_list(t_stack **lst1, t_stack **lst2, char stack,
		int *buffer)
{
	t_stack		*tmp;

	if (lst2 == NULL || *lst2 == NULL)
		return ;
	tmp = *lst2;
	ft_delone(lst2);
	ft_add(lst1, tmp);
	if ((*lst1)->prev != NULL && (*lst1)->next != NULL)
		*lst1 = (*lst1)->prev;
	if (stack == 'a')
		print_instructions(buffer, "pa\n");
	else
		print_instructions(buffer, "pb\n");
}

int		main(void)
{
	t_stack		*a;
	t_stack		*b;

	a = ft_new(1);
	ft_add(&a, ft_new(2));
	ft_add(&a, ft_new(3));
	ft_add(&a, ft_new(4));
	b = ft_new(6);
	ft_add(&b, ft_new(5));
	ft_add(&b, ft_new(7));
	ft_add(&b, ft_new(9));
	print_dlst(a);
	print_dlst(b);
	printf("\n");
	push_list(&a, &b, 'a', 0);
	print_dlst(a);
	print_dlst(b);

	return (0);
}
*/

/* test 1
int		main(void)
{
	t_stack		*a;

	a = ft_new(10);
	ft_add(&a, ft_new(11));
	ft_add(&a, ft_new(12));
	ft_add(&a, ft_new(13));
	print_dlst(a);
	ft_delone_free(&a);
	print_dlst(a);
	ft_delone_free(&a);
	print_dlst(a);
	ft_delall_free(&a, ft_listsize(a));
	return (0);
}
*/
