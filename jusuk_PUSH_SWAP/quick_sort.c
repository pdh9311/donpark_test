#include <stdio.h>

void	test_print_arr(int *arr, int len)
{
	for(int i = 0; i < len; i++)
		printf("(%d)", arr[i]);
	printf("\n\n");
}

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
		while (arr[i] < pivot)	// pivot 보다 크거나 같은 값을 찾는 과정
			i++;
		while (arr[j] > pivot)	// pivot 보다 작은거나 같은 값을 찾는 과정
			j--;
		if (i <= j)
			swap_arr(arr, i++, j--);
		printf("pivot[%d] ", pivot);
		test_print_arr(arr, right + 1);
	}
	if (left < j)
		ft_quick_sort(arr, left, j);
	if (i < right)
		ft_quick_sort(arr, i, right);

}

int		main(void)
{
//	int	arr[] = {5, 3, 7, 6, 2, 1, 4};
//	int	arr[] = {4, -3, 3, 0, -1, 2, -5, 1, -4, -2};
	int	arr[] = {3,1,0,4,7,2,5};
	int	len = sizeof(arr)/ sizeof(int);
	for (int i = 0; i < len; i ++)
		printf("[%d] ", arr[i]);
	printf("\n");
	// quickSort(arr, 0, len - 1);
	ft_quick_sort(arr, 0, len - 1);
	for (int i = 0; i < len; i ++)
		printf("[%d] ", arr[i]);
	printf("\n");
	return (0);
}
