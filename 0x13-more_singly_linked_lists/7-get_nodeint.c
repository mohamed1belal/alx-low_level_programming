#include "lists.h"

/**
  * get_nodeint_at_index - Returns the node at a given index.
  * @head: Pointer to the first node
  * @index: Index of the node to get
  *
  * Return: Pointer to the node at the given index
  */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int count = 0;
	listint_t *current = head;

	if (!head)
		return (NULL);

	while (current)
	{
		if (count == index)
			return (current);

		current = current->next;
		count++;
	}

	return (NULL);
}
