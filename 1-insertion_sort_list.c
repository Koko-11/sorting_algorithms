#include "sort.h"

/**
 * switch_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @left: The left node to swap
 * @right: The right node to swap
 */
void switch_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	if (right->next)
		right->next->prev = left;

	right->prev = left->prev;
	left->next = right->next;
	right->next = left;
	left->prev = right;
}

/**
 * insertion_sort_list - Sorts integers using Insertion Sort
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			switch_nodes(list, temp->prev, temp);
			print_list(*list);
		}
		current = current->next;
	}
}
