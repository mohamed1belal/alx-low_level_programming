#include "lists.h"

void _constructor(void) __attribute__ ((constructor));

/**
  * _constructor - exeecutes befor main()
  *
  * Return: vod
  */
void _constructor(void)
{
	printf("You're beat! and yet, you must allow,\n"
		"I bore my house upon my back!\n");
}
