#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a given index from a dlistint_t list
 * @head: Double pointer to the head of the list
 * @index: Index of the node to delete (starts at 0)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	/* 1. Başlanğıc node-u (index == 0) silmək */
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* 2. Silinəcək node-a qədər irəliləmək */
	for (i = 0; current != NULL && i < index; i++)
		current = current->next;

	/* Əgər indeksi tapmadıqsa (siyahı qısadırsa) */
	if (current == NULL)
		return (-1);

	/* 3. Ortadakı və ya sondakı node-un əlaqələrini yeniləmək */
	if (current->next != NULL)
		current->next->prev = current->prev;

	if (current->prev != NULL)
		current->prev->next = current->next;

	free(current);
	return (1);
}
