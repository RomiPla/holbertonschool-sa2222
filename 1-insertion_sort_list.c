#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list of integers to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	bool flag = false;
	listint_t *travel = NULL, *aux = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;
	travel = *list;
	while (travel->next)
	{
		if (travel->n > travel->next->n)
		{
			travel->next->prev = travel->prev; /* separar travel de la lista */
			if (travel->next->prev)
				travel->prev->next = travel->next;
			else
				*list = travel->next;
			travel->prev = travel->next; /* adjuntar travel después del sig. nodo */
			travel->next = travel->next->next; /* mover el sig. nodo hacia atrás */
			travel->prev->next = travel;
			if (travel->next)
				travel->next->prev = travel;
			travel = travel->prev;
			print_list(*list);
			if (travel->prev && travel->prev->n > travel->n) /* cambiar de nuevo */
			{
				if (!flag)
					aux = travel->next;
				flag = true;
				travel = travel->prev;
				continue;
			}
		}
		if (!flag) /* no se necesitan intercambios */
			travel = travel->next;
		else /* se hicieron todos los intercambios, continua recorriendo la lista */
			travel = aux, flag = false;
	}
}
