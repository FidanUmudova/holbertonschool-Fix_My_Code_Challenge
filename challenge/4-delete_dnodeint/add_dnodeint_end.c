#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list.
 * @head: Pointer to the pointer of the head node.
 * @n: Integer value to be stored in the new node.
 *
 * Return: Address of the new element, or NULL if it failed.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node;
	dlistint_t *last;

	if (head == NULL)
		return (NULL);

	/* 1. Yeni düyün üçün yaddaş ayırırıq */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL; 


	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	last = *head;
	while (last->next != NULL)
	{
		last = last->next;
	}

	last->next = new_node;
	new_node->prev = last;

	return (new_node);
}
