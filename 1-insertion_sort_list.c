#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list.
 *@list: what to print
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *next_node = current->next;

		current->prev = NULL;
		current->next = NULL;

		insert_sorted(&sorted, current);

		current = next_node;
	}

	*list = sorted;
}

/**
 * insert_sorted - sorts a doubly linked list.
 * @sorted: listint_t
 * @node: listint_t
 */
void insert_sorted(listint_t **sorted, listint_t *node)
{
	if (*sorted == NULL || node->n <= (*sorted)->n)
	{
		node->next = *sorted;

		if (*sorted != NULL)
			(*sorted)->prev = node;
		*sorted = node;
	}
	else
	{
		listint_t *temp = *sorted;

		while (temp->next != NULL && temp->next->n < node->n)
			temp = temp->next;

		node->next = temp->next;

		if (temp->next != NULL)
			temp->next->prev = node;
		temp->next = node;
		node->prev = temp;
	}
}
