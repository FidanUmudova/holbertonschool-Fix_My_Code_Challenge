#include "lists.h"
#include <stdlib.h>
 
/**
 * delete_dnodeint_at_index - Deletes a node at a specific index in a dlistint_t list
 * @head: Pointer to the pointer of the first node of the list
 * @index: Index of the node to delete (starts at 0)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int p;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	p = 0;
	while (current != NULL && p < index)
	{
		current = current->next;
		p++;
	}

	if (current == NULL)
		return (-1);

	if (current->next != NULL)
		current->next->prev = current->prev;

	if (current->prev != NULL)
		current->prev->next = current->next;

	free(current);

	return (1);
}
