#include "sort.h"
#include <stdio.h>
/**
* move_node - swap node with previous one
* @node: node to move
* @list: list
* Return: return a pointer to the node
*/
listint_t *move_node(listint_t *node, listint_t **list)
{
	listint_t *previous = node->prev, *current = node;

	previous->next = current->next;
	if (current->next)
		current->next->prev = previous;
	current->next = previous;
	current->prev = previous->prev;
	previous->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;

	return (current);
}

/**
* cocktail_sort_list - cocktail sort implementation
* @list: list
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	int done = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	temp = *list;
	while (done == 1)
	{
		done = 0;
		while (temp->next)
		{
			if (temp->n > temp->next->n)
			{
				temp = move_node(temp->next, list);
				done = 1;
				print_list(*list);
			}
			temp = temp->next;
		}
		if (done == 0)
			break;
		done = 1;
		while (temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				temp = move_node(temp, list);
				done = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}
