#include "sort.h"
/**
 * bubble_sort - sort an array elements
 * @array: array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{

	size_t i, idx, temp = 0;

	if (size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		for (idx = 0; idx < size; idx++)
		{
			if (array[idx] > array[idx + 1] && array[idx + 1])
			{
			temp = array[idx];
			array[idx] = array[idx + 1];
			array[idx + 1] = temp;
			print_array(array, size);
			}
		}
	}
}
