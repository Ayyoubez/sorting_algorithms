#ifndef SORT_H
#define SORT_H

#include<stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
listint_t *move_node(listint_t *node, listint_t **list);
void move(int *list, ssize_t value1, ssize_t value2);
int Lomuto(int *list, ssize_t fst, ssize_t lst, ssize_t size);
void quick_s(int *list, ssize_t fst, ssize_t lst, int size);
void shell_sort(int *array, size_t size);
#endif
