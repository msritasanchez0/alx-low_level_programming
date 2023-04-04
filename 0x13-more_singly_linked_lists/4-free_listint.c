#include "lists.h"

/**
 * free_listint - frees a listint_t list.
 * @head: pointer to a list
 */
void free_listint(listint_t *head)
{
	if (!head)
		return;
	free_listint(head->next);
	free(head);
}
