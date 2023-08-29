#include "lists.h"

/**
  * sum_listint - Returns the sum of all data in the linked list.
  * @head: Pointer to the first node
  *
  * Return: Sum of all data
  */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	if (!head)
		return (sum);

	while (current)
	{
		sum += current->n;
		current = current->next;
	}

	return (sum);
}
