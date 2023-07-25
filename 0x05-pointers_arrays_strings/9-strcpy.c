#include "main.h"

/**
  * *_stropy - copies the string pointed to by src
  * @dest: char type string
  * @src: char typr string
  * Description:  copy the string pointed to by pointer `src` to
  * the buffer pointed to by `dest`
  * Return: pointer to `dest`
  */

char *_stropy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);`
}
