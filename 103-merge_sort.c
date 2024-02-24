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
* merge_m - make a mergee
* @array: list fro start to middle
* @temp: temporary array
* @start: first element
* @middle: middle element
* @end: last element
*/

void merge_m(int *array, int *temp, int start, int middle, int end)
{
	/* sizes and arrays*/
	int size_l = middle - start + 1, size_r = end - middle;
	int *array_l, *array_r;
	/* count */
	int l, r, i = 0;

	array_l = &temp[0];
	array_r = &temp[size_r];
	for (l = 0; l < size_l; l++)
		array_l[l] = array[start + l];
	for (r = 0; r < size_r; r++)
		array_r[r] = array[middle + 1 + r];
	l = 0, r = 0, i = start;
	/* merging into main array */
	while (l < size_l && r < size_r)
	{
		if (array_l[l] <= array_r[r])
			array[i] = array_l[l], l++;
		else
			array[i] = array_r[r], r++;
		i++;
	}
	/* merging remaining into main array*/
	while (l < size_l)
		array[i] = array_l[l], l++, i++;
	/* merging remaining right into main array*/
	while (r < size_r)
		array[i] = array_r[r], r++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_l, l);
	printf("[right]: ");
	print_array(array_r, r);
	printf("[Done]: ");
	print_array(&array[start], l + r);
}
/**
* mergee_sort - sort an array of inetgers using sort alg
* @array: list of integers
* @temp: temp array
* @start: first element
* @end: last element
*/

void mergee_sort(int *array, int *temp, int start, int end)
{
	int middle;

	middle = (start + end) / 2;
	if ((start + end) % 2 == 0)
		middle--;
	if (middle >= start)
	{
		mergee_sort(array, temp, start, middle);
		mergee_sort(array, temp, middle + 1, end);
		merge_m(array, temp, start, middle, end);
	}
}
/**
* merge_sort - sort an array of integers
* @size: parameter
* @array: parameter
*/

void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;
	temp = calloc_function(size, sizeof(int));
	mergee_sort(array, temp, 0, size - 1);
	free(temp);
}
