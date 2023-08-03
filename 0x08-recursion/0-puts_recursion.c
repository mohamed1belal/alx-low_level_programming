#include "main.h"

/**
  * _puts_recursion - prints a string after printing new line
  * @s: pointer to the string
  * Return: void
  */

void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
	}
	else
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
}
