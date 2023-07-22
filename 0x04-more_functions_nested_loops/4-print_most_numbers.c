#include "main.h"

/**
  * This function prints the number from 0 to 9, execluding 2 and 4.
  */
void print_most_numbers(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		if (i != 2 && i != 4)
			printf("%d", i);
	}
	printf("\n");
}
