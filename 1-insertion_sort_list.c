#include "sort.h"
/**
* insertion_sort_list - sort a DLL
* @list: linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp;

	if (list == NULL || (*list)->next == NULL)
		return;
	temp = (*list)->next;
	while (temp)
	{
		while ((temp->prev) && (temp->prev->n > temp->n))
		{
			temp = move_node(temp, list);
			print_list(*list);
		}
		temp = temp->next;
	}
}

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
