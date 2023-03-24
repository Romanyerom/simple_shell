#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Return: Always 0
 */

int main(void)
{
	int i, n1 = 1, n2 = 2, next;

	printf("%d, %d, ", n1, n2);

	for (i = 3; i <= 98; i++)
	{
		next = n1 + n2;
		printf("%d", next);

		if (i < 98)
		{
			printf(", ");
		}

		n1 = n2;
		n2 = next;
	}

	printf("\n");

	return (0);
}
