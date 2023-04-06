#include "main.h"

/**
 * is_prime_number - checks whether a number is prime or not
 * @n: number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	/* check if n is less than 2 or even */
	if (n < 2 || (n % 2 == 0 && n != 2))
		return (0);
	/* check for factors up to the square root of n */
	int i;
	for (i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}
