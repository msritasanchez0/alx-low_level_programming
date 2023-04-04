#include "lists.h"
/**
 * add_nodeint - adds a new node at the beginning
 *	of a listint_t list
 * @head: The integer for the new node
 * @n: value to set to the new list
 *
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
		return (NULL);
	new_node->n = n;
	new_node->next = *head;

	return (new_node);
}
