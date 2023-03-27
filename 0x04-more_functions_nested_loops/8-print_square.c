#include "main.h"

/**
 * print_square - prints a square of '#' characters of a given size
 *
 * @size: the size of the square to be printed
 */

void print_square(int size)
{
	int row, column;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 0; row < size; row++)
	{
		for (column = 0; column < size; column++)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
