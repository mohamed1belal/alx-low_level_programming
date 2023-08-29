#include "lists.h"

/**
  * free_listint2 - Frees a list of integers and sets the head to NULL.
  * @head: Address of pointer to the first node
  *
  * Description: This function frees a linked list of integers and sets
  *              the head pointer to NULL to indicate an empty list.
  *
  * Return: void
  */
void free_listint2(listint_t **head)
{
	listint_t *node, *temp;

	if (!head)
		return;

	node = *head;
	while (node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
	*head = NULL;
}
