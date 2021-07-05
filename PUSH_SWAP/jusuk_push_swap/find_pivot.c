#include "push_swap.h"

void		swap_arr(int *arr, int index_1, int index_2)
{
	int			tmp;

	tmp = arr[index_1];
	arr[index_1] = arr[index_2];
	arr[index_2] = tmp;
}
/*
void		ft_quick_sort(int *arr, int len)
{
	int			pivot;
	int			i;
	int			j;

	if (len == 0 || len == 1 || len == 2)
	{
		if (len == 2 && arr[0] > arr[1])
			swap_arr(arr, 0, 1);
		return ;
	}
	pivot = arr[len - 1];
	i = 0;
	j = len - 2;
	printf("++++++++1\n");
	printf("# ");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("#\n");
	while (i <= j)
	{
	printf("\n1) left[%d], right[%d], pivot[%d]\n", i, j, pivot);
		while (arr[i] < pivot)			// pivot 보다 작으면 index 증가
			i++;
		while (arr[j] > pivot)		// pivot 보다 크면 index 감소
			j--;
		if (i <= j)			// 왼쪽 오른쪽 index가 같거나 서로 넘어가지 않았다면
			swap_arr(arr, i, j);
	printf("2) left[%d], right[%d], pivot[%d]\n", i, j, pivot);
	printf("( ");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf(")\n");
	}
	printf("\n{ ");
	for (int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("}\n");
	printf("++++++++2\n");
	swap_arr(arr, i, len - 1);
	ft_quick_sort(arr, i);				// pivot 의 왼쪽을 정렬
	ft_quick_sort(&arr[i + 1], len - i - 1);	// pivot의 오른쪽을 정렬
}
*/

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
		while (arr[i] < pivot)	// pivot 보다 크거나 같은 값을 찾는 과정
			i++;
		while (arr[j] > pivot)	// pivot 보다 작은거나 같은 값을 찾는 과정
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
	ft_quick_sort(arr, 0, len - 1);	// 입력받은 인자들을 정렬한다.
	result.pivot_l = arr[len / 3];			// 정렬된 인자들에 1/3 위치의 값을 pivot_l로 잡는다.
	result.pivot_h = arr[len * 2 / 3];		// 정렬된 인자들에 2/3 위치의 값을 pivot_h로 잡는다.
	free(arr);
	return (result);
}
