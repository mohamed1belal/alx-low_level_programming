#include "main.h"

/**
  * _strncat - a function that concatenates two strings.
  *
  * @dest: pointer to description input
  * @src: pointer to source input
  * @n: most numbers of bytes from @src
  *
  * Return: @dest
  */

char *_strncat(char *dest, char *src, int n)
{
	int c, i;

	c = 0;

	/*find the size of dest array*/
	while (dest[c])
		c++;

	/**
	  * src does not need to be null terminated
	  * if it contains n of more bytes
	  */
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[c + i] = src[i];
	/*null terminates dest*/
	dest[c + i] = '\0';

	return (dest);
}
