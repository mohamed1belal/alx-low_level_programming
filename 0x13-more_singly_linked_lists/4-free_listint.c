#include "lists.h"

/**
  * free_listint - frees a list of integers
  * @head: pointer to the first node
  *
  * Return: void
  */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head)
	{
		current = head;
		head = head->next;

		current->next = NULL;
		free(current);
	}
}
