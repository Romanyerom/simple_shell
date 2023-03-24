#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int first = 1, second = 2, next = 0;
	long sum = 2;

	while (next <= 4000000)
	{
		next = first + second;
		first = second;
		second = next;

		if (next % 2 == 0)
			sum += next;
	}

	printf("%ld\n", sum);

	return (0);
}
