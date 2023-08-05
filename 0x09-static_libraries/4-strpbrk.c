#include "main.h"

/**
  * _strpbrk - search a string for any of a set of bytes
  * @s: string
  * @accept: string to match
  * Return: pointer to the type in s that matches one of the bytes in accept
  * or NULL if no such byte is found.
  */

char *_strpbrk(char *s, char *accept)
{
	int it, jit;
	char *p;

	it = 0;
	while (s[it] != '\0')
	{
		jit = 0;
		while (accept[jit] != '\0')
		{
			if (accept[jit] == s[it])
			{
				p = &s[it];
				return (p);
			}
			jit++;
		}
		it++;
	}

	return (0);
}
