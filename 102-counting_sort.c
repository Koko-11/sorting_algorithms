#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of ints using Counting Sort
 * @array: The array to sort
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count_array, *output_array;
	size_t i;
	int max_val = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}

	count_array = malloc((max_val + 1) * sizeof(int));
	if (count_array == NULL)
		return;
	output_array = malloc(size * sizeof(int));
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}

	for (i = 0; i <= (size_t)max_val; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	print_array(count_array, max_val + 1);

	for (i = 1; i <= (size_t)max_val; i++)
		count_array[i] += count_array[i - 1];

	for (i = size; i > 0; i--)
	{
		output_array[count_array[array[i - 1]] - 1] = array[i - 1];
		count_array[array[i - 1]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(count_array);
	free(output_array);
}
