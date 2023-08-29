#include "lists.h"

/**
  * delete_nodeint_at_index - Deletes the node at a given index.
  * @head: Address of pointer to the first node
  * @index: Index of the node to delete
  *
  * Return: 1 on success, -1 on failure
  */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head;
	listint_t *prev_node = NULL;
	unsigned int i = 0;


	if (!head || !*head)
		return (-1);

	if (index == 0)
	{
		listint_t *node = *head;
		*head = (*head)->next;
		free(node);
		return (1);
	}

	for (i = 0; current && i < index; i++)
	{
		prev_node = current;
		current = current->next;
	}

	if (!current)
		return (-1);

	prev_node->next = current->next;
	free(current);

	return (1);
}
