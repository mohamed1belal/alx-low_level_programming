#include "main.h"

/**
  * swap_int - writes two values of two integers
  *		using two input parameters
  *
  * @c: input parameter 1
  * @n: input parameter 2
  *
  * Return: Nothing
  */

void swap_int(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
