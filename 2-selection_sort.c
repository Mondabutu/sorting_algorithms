#include "sort.h"

/**
 * swap_pos - this swaps position of values in array
 *
 * @array: array to be changed
 * @first: first index
 * @second: second index
 */
void swap_pos(int **array, size_t first, size_t second)
{
	int h;

	h = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = h;
}

/**
 * selection_sort - uses the selection algo to sort
 * an array
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t k, j;
	int min_val, min_index, flag;

	if (size < 2)
		return;

	for (k = 0; k < size; k++)
	{
		min_val = array[k];
		min_index = k;
		flag = 0;

		for (j = k + 1; j < size; j++)	/* start from the unsorted part */
		{
			if (min_val > array[j])  /* check for min value */
			{
				min_val = array[j];
				min_index = j;
				flag = 1;
			}
		}

		if (flag)
		{
			swap_pos(&array, k, min_index);
			print_array(array, size);
		}
	}
}
