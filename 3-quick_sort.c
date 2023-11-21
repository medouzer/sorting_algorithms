#include "sort.h"

/**
 * partition - partition an array using Lomuto
 * @array: array of integers
 * @start: the start index of array
 * @end: the last index of array
 * @size: size of array
 * Return: index of pivot
 */

int partition(int *array, int start, int end, size_t size)
{
	int i = start - 1;
	int pivot = array[end];
	int j, tmp;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[end] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_r - recursive function
 * @array: array of integers
 * @start: start index of array
 * @end: end index of array
 * @size: size of array
 * Return: void
 */

void	quick_sort_r(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		quick_sort_r(array, start, pivot - 1, size);
		quick_sort_r(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - sort an array using quick sort
 * @array: array of integers
 * @size: size of array
 * Return: void
 */

void	quick_sort(int *array, size_t size)
{
	if (size < 2 || !array)
		return;
	quick_sort_r(array, 0, size - 1, size);
}
