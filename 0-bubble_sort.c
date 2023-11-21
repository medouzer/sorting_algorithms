#include "sort.h"

/**
 * bubble_sort - bubble sort algo
 * @array: the array to sort
 * @size: the size of the array
 */

void	bubble_sort(int *array, size_t size)
{
	size_t	i,	j;
	int		temp;

	if (size < 2 || !array)
		return;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (array[j] < array[j - 1])
			{
				temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
				print_array(array, size);
			}
			j++;
		}
		i++;
	}
}
