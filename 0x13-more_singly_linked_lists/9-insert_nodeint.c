#include "lists.h"

/**
  * insert_nodeint_at_index - Inserts a new node at a given index.
  * @head: Address of pointer to the first node
  * @idx: Index at which to insert the new node
  * @n: Value for the new node
  *
  * Return: Address of the new node, or NULL if failed
  */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{

	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current = *head;
	unsigned int i;

	if (!head)
		return (NULL);

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = (NULL);

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	for (i = 0; current && i < idx - 1; i++)
	{
		current = current->next;
	}

	if (!current)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
