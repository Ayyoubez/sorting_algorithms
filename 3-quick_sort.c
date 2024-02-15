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
* Lomuto - LOmuto sorting
* @list: list
* @fst: first element
* @lst: last element
* @size: size of the list
* Return: return position of last
*/

int Lomuto(int *list, ssize_t fst, ssize_t lst, ssize_t size)
{
	int pi = list[lst];
	ssize_t current = fst, find;

	for (find = fst; find < lst; find++)
	{
		if (list[find] < pi)
		{
			if (list[current] != list[find])
			{
				move(list, current, find);
				print_array(list, size);
			}
			current++;
		}
	}
	if (list[current] != list[lst])
	{
		move(list, current, lst);
		print_array(list, size);
	}
	return (current);
}
/**
* quick_s - algorithm
* @list: list
* @fst: first element
* @lst: last element
* @size: size of the list
*/

void quick_s(int *list, ssize_t fst, ssize_t lst, int size)
{
	ssize_t pos = 0;

	if (fst < lst)
	{
		pos = Lomuto(list, fst, lst, size);

		quick_s(list, fst, pos - 1, size);
		quick_s(list, pos + 1, lst, size);
	}
}

/**
* quick_sort - quick sort algorithm
* @array: list
* @size: list size
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_s(array, 0, size - 1, size);
}
