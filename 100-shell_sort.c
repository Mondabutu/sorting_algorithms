#include "sort.h"

/**
 * find_pow - find power of a number
 * @x: the number
 * @y: the value of power
 *
 * Return: the power of x
 */
int find_pow(int x, size_t y)
{
	if (y == 0)
		return (1);

	return (x * find_pow(x, y - 1));
}

/**
 * seq_generator - generate sequence
 * @size: size of sequence
 *
 * Return: pointer to the address of sequence
 */
int *seq_generator(size_t size)
{
	size_t n = 0;
	int k = 0, nth_term, *sequence;

	sequence = malloc(sizeof(int) * size);
	if (sequence == NULL)
		return (NULL);

	nth_term = 0;
	while (n < size)
	{
		nth_term = nth_term + find_pow(3, n);
		sequence[k] = nth_term;
		n++;
		k++;
	}
	return (sequence);
}

/**
 * reverse_seq - reverse sequence
 * @sequence: pointer to the address of sequence
 * @size: size of sequence
 *
 * Return: sequence in reverse
 */
int *reverse_seq(int *sequence, size_t size)
{
	int *rev_seq;
	size_t k = 0, seq_index;

	rev_seq = malloc(sizeof(int) * size);
	if (rev_seq == NULL)
		return (NULL);

	seq_index = size - 1;
	while (k < size)
	{
		rev_seq[k] = sequence[seq_index];
		k++;
		seq_index--;
	}
	return (rev_seq);
}

/**
 * shell_sort - sorts using the Shell sort algorithm
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: nothing
 */
void shell_sort(int *array, size_t size)
{
	int j, flag = 0;
	int temp, *sequence, *rev_seq, hold;
	size_t k, seq_index = 0;

	sequence = seq_generator(size);
	if (sequence == NULL)
		return;

	rev_seq = reverse_seq(sequence, size);
	if (rev_seq == NULL)
		return;

	while (seq_index < size)
	{
		for (k = rev_seq[seq_index]; k < size; k++)
		{
			temp = array[k];
			hold = rev_seq[seq_index];
			for (j = k; j >= hold && array[j - hold] > temp; j -= hold)
			{
				array[j] = array[j - rev_seq[seq_index]];
			}
			array[j] = temp;
			flag = 1;
		}
		if (flag)
			print_array(array, size);
		seq_index++;
	}
	free(sequence);
	free(rev_seq);
}
