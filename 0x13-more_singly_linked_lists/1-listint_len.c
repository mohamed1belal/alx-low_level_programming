#include "lists.h"

/**
  * listint_len - Returns the number of elements in a linked list.
  * @h: Pointer to the first node
  *
  * Return: Number of elements in the list
  */
size_t listint_len(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current = h;

	while (current)
	{
		current = current->next;
		count++;
	}
	return (count);
}

