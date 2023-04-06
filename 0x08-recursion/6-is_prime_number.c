#include "main.h"

/**
 * is_prime_number - checks whether a number is prime or not
 * @n: number to check
 *
 * Return: 1 if n is prime, 0 otherwise
 */

int is_prime_helper(int n, int i);

int is_prime_number(int n)
{
	int i;

	if (n <= 1)
		return (0);

	i = 2;
	while (i <= n / 2)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}
