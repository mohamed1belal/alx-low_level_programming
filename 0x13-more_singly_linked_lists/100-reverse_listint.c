#include "lists.h"

/**
  * reverse_listint - Reverses an int list.
  * @head: Address of pointer to the first node
  *
  * Return: Address of the new head
  */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *current = *head;
	listint_t *next = NULL;

	if (!head || !*head)
		return (NULL);

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}

	*head = prev;
	return (*head);
}
