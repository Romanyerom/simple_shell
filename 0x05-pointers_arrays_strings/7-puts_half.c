#include "main.h"

/**
 * puts_half - Prints half of a string.
 * @str: The string to be printed.
 */
void puts_half(char *str)
{
	int length = 0;
	int i;

	/* Find the length of the string */
	while (str[length] != '\0')
	{
		length++;
	}

	/* Print the second half of the string */
	for (i = (length + 1) / 2; i < length; i++)
	{
		_putchar(str[i]);
	}

	/* Print a new line at the end */
	_putchar('\n');
}
