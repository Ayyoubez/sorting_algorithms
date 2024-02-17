#include "sort.h"
/**
* move - change the position
* @list: list
* @value1 : element value
* @value2 : element value
*/

void move(int *list, ssize_t value1, ssize_t value2)
{
	int temp;

	temp = list[value1];
	list[value1] = list[value2];
	list[value2] = temp;
}

/**
* shell_sort - function sortiing using shell sort algorithm
* @size: size of the array
*@array: of elements
*/

void shell_sort(int *array, size_t size)
{
	size_t ga = 1, i, idx = 0;

	if (array == NULL || size < 2)
		return;
	while (ga < size / 3)
		ga = 3 * ga + 1;
	while (ga >= 1)
	{
		for (i = ga; i < size; i++)
			for (idx = i; idx >= ga && (array[idx] < array[idx - ga]); idx -= ga)
				move(array, idx, idx - ga);
		print_array(array, size);
		ga /= 3;
	}
}
