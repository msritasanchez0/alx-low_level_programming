#include "lists.h"
#include <stdio.h>

/**
 * listint_len - returns the number of elements
 *		in a linked listint_t list
 * @h: pointer to the linked list
 *
 * Return: elements of the linked list
 */
size_t listint_len(const listint_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);
	while (h)
	{
		nodes++;
		h = h->next;
	}
	return (nodes);
}

