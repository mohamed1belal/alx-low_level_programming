#include "main.h"
#include "stdio.h"

/**
  * string_nconcat - concatenates two strings
  * @s1: pointer to the first string.
  * @s2: pointer to 2nd string.
  * @n: Number of bytes from n2 to concatenated string.
  *
  * Return: pointer to space in memory containing concatenated string.
  */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *str;
	unsigned int i, j, s1_len, s2_len;

	/*check if the string passed are null*/
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	/*Compute the length of the strings*/

	for (s1_len = 0; s1[s1_len] != '\0'; s1_len++)
		;

	for (s2_len = 0; s2[s2_len] != '\0'; s2_len++)
		;
	/*Memory reservation-for case 1 & 2.*/
	str = malloc(s1_len + n + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	/*copy first string into str.*/
	for (i = 0; s2[i] != '\0'; i++)
		str[i] = s1[i];
	/*copy secound string into str.*/
	for (j = 0; j < n; j++)
	{
		str[i] = s2[j];
		i++;
	}

	str[i] = '\0';
	return (str);
}
