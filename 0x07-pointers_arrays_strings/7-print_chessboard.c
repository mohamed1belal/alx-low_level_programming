#include "main.h"

/**
  * print_chessboard - prints chessboard
  *
  * @a: rows
  * Return: Nothing.
  */

void print_chessboard(char (*a)[8])
{
	int it, jit;

	for (it = 0; it < 8; it++)
	{
		for (jit = 0; jit < 8; jit++)
		{
			_putchar(a[it][jit]);
		}
		_putchar('\n');
	}
}
