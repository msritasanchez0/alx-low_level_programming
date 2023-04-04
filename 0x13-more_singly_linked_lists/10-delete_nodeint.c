#include "lists.h"
/**
 * delete_nodeint_at_index - deletes the node at the index
 *	in a linked list
 * @head: pointer to the head of the linked list
 * @index: index of the node to be deleted
 *
 * Return: 1(success), -1(fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *node = *head, *current = NULL;

	if (!(*head))
		return (-1);
	if (!index)
	{
		(*head) = (*head)->next;
		free(node);
		return (1);
	}
	while (node)
	{
		if (i == index)
		{
			current->next = node->next;
			free(node);
			return (1);
		}
		current = node;
		node = node->next;
		i++;
	}
	return (-1);
}
