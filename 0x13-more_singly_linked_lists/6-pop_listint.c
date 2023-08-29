#include "lists.h"

/**
  * pop_listint - Pops the head node of a linked list.
  * @head: Address of pointer to the first node
  *
  * Description: This function removes the first node from a linked list
  *              and returns its value. If the list is empty or the head
  *              pointer is NULL, it returns 0.
  *
  * Return: Value of the popped node
  */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int n = 0;

	if (head && *head)
	{
		temp = *head;
		n = temp->n;
		*head = (*head)->next;
		free(temp);
	}
	return (n);
}
