#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Return: Always 0
 */

int main(void)
{
	unsigned long int a = 1, b = 2, sum;
	int i;

	printf("%lu, %lu", a, b);

	for (i = 2; i < 98; i++)
	{
		sum = a + b;
		printf(", %lu", sum);
		a = b;
		b = sum;
	}

	printf("\n");

	return (0);
}
