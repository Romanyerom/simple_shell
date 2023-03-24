#include <stdio.h>

/**
 * print_to_98 - Prints all natural numbers from n to 98, followed by a newline
 * @n: The starting number
 *
 * Return: void
 */

void print_to_98(int n)
{
	/* loop from n to 98 */
	while (n != 98)
	{
		/* print the current number */
		printf("%d, ", n);

		/* increment or decrement n based on its value relative to 98 */
		if (n < 98)
			n++;
		else
			n--;
	}

	/* print the final number, 98 */
	printf("98\n");
}
