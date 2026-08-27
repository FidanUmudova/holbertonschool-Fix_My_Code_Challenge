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
	dlistint_t *tmp = *head;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = tmp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(tmp);
		return (1);
	}

	for (i = 0; tmp != NULL && i < index; i++)
		tmp = tmp->next;

	if (tmp == NULL)
		return (-1);

	if (tmp->next != NULL)
		tmp->next->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = tmp->next;

	free(tmp);
	return (1);
}
