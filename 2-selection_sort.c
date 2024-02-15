#include "sort.h"

/**
* selection_sort - sorts an array
* @size: array size
* @array: list
*/

void selection_sort(int *array, size_t size)
{
	size_t idx, i;
	int temp, move, flag = 0;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		temp = i;
		flag = 0;
		for (idx = i + 1; idx < size; idx++)
		{
			if (array[temp] > array[idx])
			{
				temp = idx;
				flag += 1;
			}
		}
		move = array[i];
		array[i] = array[temp];
		array[temp] = move;
		if (flag != 0)
			print_array(array, size);
	}
}
