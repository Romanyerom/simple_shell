#include "main.h"

/**
 * _puts_recursion - Prints a string using recursion
 * @s: The string to be printed
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n'); /* prints a new line if end of string is reached */
		return;
	}

	_putchar(*s);
	/* prints the current character of the string */
	_puts_recursion(s + 1);
	/* calls the function recursively for the next character */
}
