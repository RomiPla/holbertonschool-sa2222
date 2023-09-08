#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using insertion sort.
 * @list: Pointer to a pointer to the head of the list.
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

		if (sorted == NULL || current->n <= sorted->n)
		{
			current->next = sorted;
			current->prev = NULL;

			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			listint_t *temp = sorted;

			while (temp->next != NULL && temp->next->n < current->n)
				temp = temp->next;

			current->next = temp->next;
			current->prev = temp;

			if (temp->next != NULL)
				temp->next->prev = current;
			temp->next = current;
		}

		current = next_node;
	}

	*list = sorted;
}

