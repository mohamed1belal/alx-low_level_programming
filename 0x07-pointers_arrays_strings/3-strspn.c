#include "main.h"

/**
  * _strspn - the lenght of a prefix substring
  *
  * @s: string
  * @accept: bytes.
  * Return: unsigned int.
  */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int it, jit;

	for (it = 0; s[it] != '\0'; it++)
	{
		for (jit = 0; accept[jit] != s[it]; jit++)
		{
			if (accept[jit] == '\0')
				return (it);
		}
	}
	return (it);
}
