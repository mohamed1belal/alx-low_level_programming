#include "lists.h"

/**
  * print_listint - prints a linked list
  * @h: pointer to the first node
  *
  * Return: size of list
  */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;
	const listint_t *current = h;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
		count++;
	}
	return (count);
}
