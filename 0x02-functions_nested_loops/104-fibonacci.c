#include <stdio.h>

/**
 * main - Prints the first 98 Fibonacci numbers
 *
 * Return: Always 0
 */

int main(void)
{
	unsigned long int fib1 = 1, fib2 = 2, next_fib;
	int i;

	printf("%lu, %lu", fib1, fib2);

	for (i = 2; i < 98; i++)
	{
		next_fib = fib1 + fib2;
		printf(", %lu", next_fib);
		fib1 = fib2;
		fib2 = next_fib;
	}
	printf("\n");

	return (0);
}