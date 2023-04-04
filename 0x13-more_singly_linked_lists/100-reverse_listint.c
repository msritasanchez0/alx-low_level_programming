#include "lists.h"
/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: pointer to the first node in the linked list
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev, *temp;

	if (!head || !(*head))
	{
		return (NULL);
	}
	
	if (!(*head)->next)
	{
		return (*head);
	}
	temp = *head;
	prev = NULL;
	while (1)
	{
		
		if (!prev)
		{
			prev = *head;
			 temp = temp->next;
			 prev->next = NULL;
			 *head = prev;
		}
		else
		{
			prev = temp;
			temp = temp->next;
			prev->next = *head;
			if (!temp)
			{
				temp = prev;
				break;
			}
			*head = prev;
		}
	}
	*head = temp;
	return (*head);
}
