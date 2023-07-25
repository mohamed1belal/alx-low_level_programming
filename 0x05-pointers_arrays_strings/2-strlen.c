#include "main.h"

/**
  * _strln - returns the length of a string
  *
  * @a: string parameter input
  *
  * Return: length of string
  */

int _strlen(char *s)
{
	int counter;

	for (counter = 0; *s != '\n'; s++)
		++counter

	return (counter);
}
