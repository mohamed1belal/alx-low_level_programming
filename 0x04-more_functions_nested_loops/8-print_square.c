#include "main.h"

/**
  * print_square - print a square using the character #
  *
  * @size: is the size of the square
  *
  * Return: Always 0 (Success)
  */

void print_square(int size)
{
	int row, cloumn;

	for (row = 1; row <= size; row++)
	{
		for (cloumn = 1; cloumn <= size; column++)
			_putchar('#');
		_putchar('\n');
	}
}
