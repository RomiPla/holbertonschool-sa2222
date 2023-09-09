#include "sort.h"

/**
 * swap_ints - swaps the value of two integers via pointers
 * @a: int
 * @b: int
 */

void swap_ints(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - split the arrangement
 * @array: int
 * @size: size_t
 * @left: int
 * @right: int
 * Return: above
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot = array + right, above = left;
	int below;

	for (below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above != below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - minor on the left and major on the right
 * @array: int
 * @size: size_t
 * @left: int
 * @right: int
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	if (left < right)
	{
		int part = lomuto_partition(array, size, left, right);

		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sorts n array of integers in ascending order
 * @array: int
 * @size: size-t
 */

void quick_sort(int *array, size_t size)
{
	if (array && size > 1)
		lomuto_sort(array, size, 0, size - 1);
}
