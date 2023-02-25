#include "sort.h"

/**
 * arr_zero_init - initialize array by 0
 *
 * @array: array to be initialized
 * @size: size of the array
 */
void arr_zero_init(int *array, int size)
{
	int k;

	for (k = 0; k < size; k++)
		array[k] = 0;
}

/**
 * get_max - gets the maximum value in the array
 *
 * @array: array to get max value from
 * @size: size of the array
 *
 * Return: maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t k;

	if (size < 2)
		return (0);

	max = array[0];	/* start from first index */

	for (k = 1; k < size; k++)
	{
		if (max < array[k])
			max = array[k];
	}

	return (max);
}

/**
 * counting_sort - sorts an array using the counting
 * sort algorithm
 *
 * @array: initial array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int k = get_max(array, size), j, *position, *sumPosition, *sorted;
	size_t k;

	if (k == 0)
		return;

	position = malloc(sizeof(int) * (k + 1));
	if (!position)
		return;
	arr_zero_init(position, k + 1);

	for (k = 0; k < size; k++)
		position[array[k]] += 1;    /* set one to the positions */

	sumPosition = malloc(sizeof(int) * (k + 1));
	if (!sumPosition)
		return;
	arr_zero_init(sumPosition, k + 1);
	sumPosition[0] = position[0];   /* make first index equal */

	for (j = 1; j < (k + 1); j++)
		sumPosition[j] = position[j] + sumPosition[j - 1];

	free(position), print_array(sumPosition, k + 1);

	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return;
	arr_zero_init(sorted, size);

	for (k = 0; k < size; k++)  /* get the sorted array */
	{
		sumPosition[array[k]] -= 1;
		sorted[sumPosition[array[k]]] = array[k];
	}
	free(sumPosition);

	for (k = 0; k < size; k++)  /* update array */
		array[k] = sorted[k];
	free(sorted);
}
