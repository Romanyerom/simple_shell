#include "main.h"

/**
 * print_number - Prints an integer.
 *
 * @n: Integer to be printed.
 *
 * Return: void.
 */
void print_number(int n)
{
	unsigned int n_copy;

	if (n < 0)
	{
		_putchar('-');
		n_copy = -n;
	}
	else
		n_copy = n;

	if (n_copy / 10)
		print_number(n_copy / 10);

	_putchar((n_copy % 10) + '0');
}
