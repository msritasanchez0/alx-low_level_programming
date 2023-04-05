#include "lists.h"
/**
<<<<<<< HEAD
 * delete_nodeint_at_index - deletes a node in a linked list
 * @index: index of the node to delete
 * @head: pointer to the first element in the linked list
=======
 * delete_nodeint_at_index - deletes the node at the index
 *	in a linked list
 * @head: pointer to the head of the linked list
 * @index: index of the node to be deleted
>>>>>>> 3ec911e62e43009121a377104b627848094c6537
 *
 * Return: 1(success), -1(fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
<<<<<<< HEAD
	unsigned int i;
	listint_t *temp = *head;
	listint_t *current;


=======
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
>>>>>>> 3ec911e62e43009121a377104b627848094c6537
