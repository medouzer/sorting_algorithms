#include "sort.h"

/**
 * insertion_sort_list - sort a doubly linked list with insertion sort
 * @list: doubly linked list of integers
 * Return: void
 */

void	insertion_sort_list(listint_t **list)
{
	listint_t	*i,	*tmp,	*cur;

	if (!list || !*list || !(*list)->next)
		return;
	cur = (*list)->next;
	while (cur)
	{
		i = cur;
		while (i->prev && i->n < i->prev->n)
		{
			tmp = i->prev;
			if (tmp->prev)
				tmp->prev->next = i;
			i->prev = tmp->prev;
			tmp->prev = i;
			tmp->next = i->next;
			if (i->next)
				i->next->prev = tmp;
			i->next = tmp;
			if (!i->prev)
				*list = i;
			print_list(*list);
		}
		cur = cur->next;
	}
}
