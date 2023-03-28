#include "main.h"

/**
 * puts2 - Prints every other character of a string.
 * @str: The string to be printed.
 */
void puts2(char *str)
{
	int i;

	/* Iterate through the string, incrementing by 2 each time */
	for (i = 0; str[i] != '\0'; i += 2)
	{
		_putchar(str[i]);
	}

	/* Print a new line at the end */
	_putchar('\n');
}
