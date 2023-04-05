#include "lists.h"
/**
 * delete_nodeint_at_index - deletes a node in a linked list
 * @index: index of the node to delete
 * @head: pointer to the first element in the linked list
 *
 * Return: 1(success), -1(fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *temp = *head;
	listint_t *current;


