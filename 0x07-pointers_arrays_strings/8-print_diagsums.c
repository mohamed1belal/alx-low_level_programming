#include "main.h"
#include <stdio.h>

/**
  * print_diagsums - description
  * @a: 2d array of int types
  * @size: size of array (square)
  */

void print_diagsums(int *a, int size)
{
	int it, s1 = 0, s2 = 0;

	for (it = 0; it < size; it++)
	{
		s1 += a[it];
		s2 += a[size - it - 1];
		a += size;
	}
	printf("%d, ", s1);
	printf("%d\n", s2);
}
