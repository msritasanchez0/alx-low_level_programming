#include "lists.h"
/**
 * pop_listint - deletes the head node and returnsits data
 * @head: pointer to the first node in linked list
 *
 * Return: the head node’s data (n).
 *	or 0 if empty
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int num;

	if (!(*head) || !head)
		return (0);

	temp = (*head)->next;
	num = (*head)->n;
	free(*head);
	*head = temp;

	return (num);
}
