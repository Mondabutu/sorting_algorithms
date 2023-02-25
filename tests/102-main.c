#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 9, 9, 71, 13, 52, 96, 73, 7, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	counting_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
