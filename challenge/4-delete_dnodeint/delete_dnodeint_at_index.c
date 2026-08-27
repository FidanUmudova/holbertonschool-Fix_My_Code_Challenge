#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at index of a dlistint_t list
 * @head: Pointer to the pointer of the first node
 * @index: Index of the node that should be deleted (starts at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *h1;
	dlistint_t *h2;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	h1 = *head;

	if (index == 0)
	{
		*head = h1->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(h1);
		return (1);
	}

	for (i = 0; i < index && h1 != NULL; i++)
	{
		h2 = h1;
		h1 = h1->next;
	}

	if (h1 != NULL)
	{
		h2->next = h1->next;
		if (h1->next != NULL)
			h1->next->prev = h2;
		free(h1);
		return (1);
	}

	return (-1);
}
