#include "main.h"

/**
 * check_sqrt - checks for the square root of n
 * @n: number to find the square root of
 * @i: current number to check for square root
 *
 * Return: the square root of n, -1 if there is no natural square root
 */
int check_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (check_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find the square root of
 *
 * Return: the square root of n, -1 if there is no natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (check_sqrt(n, 0));
}
