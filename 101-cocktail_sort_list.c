#include "sort.h"

/**
 * switch_nodes - Switches two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
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
 * cocktail_sort_list - Sorts integers using Cocktail Shaker Sort
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start, *end;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		start = *list;

		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				switch_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
			else
				start = start->next;
		}
		end = start;

		if (swapped == 0)
			break;

		swapped = 0;

		while (end->prev != NULL)
		{
			if (end->n < end->prev->n)
			{
				switch_nodes(list, end->prev, end);
				print_list(*list);
				swapped = 1;
			}
			else
				end = end->prev;
		}
		start = end->next;
	} while (swapped);
}
