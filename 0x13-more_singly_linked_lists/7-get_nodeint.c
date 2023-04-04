#include "lists.h"
/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the head of the list
 * @index: index of the node to return starting at 0
 *
 * Return: pointer to the node in the linked list
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp;

	if (!head)
		return (NULL);

	temp = head;
	while (i < index)
	{
		if (!temp)
			return (NULL);
		temp = temp->next;
		i++;
	}
	return (temp);
}
