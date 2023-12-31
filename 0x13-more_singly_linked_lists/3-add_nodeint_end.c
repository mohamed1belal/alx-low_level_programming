#include "lists.h"

/**
  * add_nodeint_end - adds a node to the end of a linked list
  * @head: pointer to the first node
  * @n: value for new node
  *
  * Return: pointer to new node
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *last;

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}

	last = *head;
	while (last->next)
		last = last->next;

	last->next = new_node;

	return (new_node);
}
