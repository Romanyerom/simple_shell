#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the numbers from 1 to 100, with Fizz for multiples of
 * three,Buzz for multiples of five, and FizzBuzz for multiples of both three
 * and five.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i;

	for (i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			printf("FizzBuzz ");
		}
		else if (i % 3 == 0)
		{
			printf("Fizz ");
		}
		else if (i % 5 == 0)
		{
			printf("Buzz ");
		}
		else
		{
			printf("%d ", i);
		}
	}

	printf("\n");

	return (0);
}
