#include "lists.h"

static listint_t *new_node(const int n);

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head: pointer to the linked list
 * @idx: index of the new list where node is to inserted
 * @n: data to insert to the new node
 *
 * Return: pointer to the head, NULL  if failed.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new, *temp = *head;

	if (!(*head) && idx == 0)
	{
		*head = new_node(n);
		return (*head);
	}

	i = 0;
	while (temp)
	{
		if (idx == 0)
		{
			*head = new_node(n);
			(*head)->next = temp;
			return (*head);
		}
		else if (i == idx - 1)
		{
			new = new_node(n);
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		temp = temp->next;
		i++;
	}
	return (NULL);
}
/**
 * new_node - forms a new listint_t node
 * @n: integer to be inserted into the node
 *
 * Return: pointer to the node
 */
static listint_t *new_node(const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;
	return (new);
}
