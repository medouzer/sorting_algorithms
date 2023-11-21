#include "sort.h"

/**
 * selection_sort - selection sort for an array
 * @array: the array to sort
 * @size: the size of the array
 */

void	selection_sort(int *array, size_t size)
{
	int tmp, small;
	size_t i, j;

	if (!array || size < 2)
		return;
	i = 0;
	while (i < size - 1)
	{
		small = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[small])
				small = j;
			j++;
		}
		if (small != (int)i)
		{
			tmp = array[i];
			array[i] = array[small];
			array[small] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
