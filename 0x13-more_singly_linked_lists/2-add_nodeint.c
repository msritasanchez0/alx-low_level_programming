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
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = *head;

	return (new);
}
