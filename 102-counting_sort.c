#include "sort.h"
#include <stdio.h>
/**
* calloc_function - calloc function
* @element: number element
* @size: bit size of each element
* Return: return a pointer to the memory
*/

void *calloc_function(unsigned int element, unsigned int size)
{
	unsigned int i = 0;
	char *ptr;

	if (element == 0 || size == 0)
		return ('\0');
	ptr = malloc(element * size);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < (element * size); i++)
		ptr[i] = '\0';
	return (ptr);
}
/**
* counting_sort - counting sort method
* @array: array
* @size: array size
*/

void counting_sort(int *array, size_t size)
{
	int idx, max = 0, *count = '\0', *tmp = '\0';
	size_t i;

	if (array == NULL || size < 2)
		return;
	/* max number*/
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	count = calloc_function(max + 1, sizeof(int));
	tmp = calloc_function(size + 1, sizeof(int));
	/* counter for array */
	for (i = 0; i < size; i++)
		count[array[i]]++;
	/* new values*/
	for (idx = 1; idx <= max; idx++)
		count[idx] += count[idx - 1];
	print_array(count, max + 1);
	/* new array */
	for (i = 0; i < size; ++i)
	{
		tmp[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/* replace arrays */
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
	free(count);
}
