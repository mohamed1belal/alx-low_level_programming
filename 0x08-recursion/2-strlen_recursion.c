#include "main.h"

/**
  * _strlen_recursion - returns the lenght of a string
  * @s: pointer the string
  * Return: int
  */

int _strlen_recursion(char *s)
{
	int ntrr = 0;

	if (*s > '\0')
	{
		ntrr += _strlen_recursion(s + 1) + 1;
	}

	return (ntrr);
}
