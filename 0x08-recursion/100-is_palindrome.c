#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string
 * @s: Pointer to the string
 *
 * Return: Length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + _strlen_recursion(s + 1));
}

/**
 * check_palindrome - Checks if a string is a palindrome
 * @s: Pointer to the string
 * @i: Starting index
 * @j: Ending index
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int check_palindrome(char *s, int i, int j)
{
	if (i >= j)
		return (1);

	if (s[i] != s[j])
		return (0);

	return (check_palindrome(s, i + 1, j - 1));
}

/**
 * is_palindrome - Determines if a string is a palindrome
 * @s: Pointer to the string
 *
 * Return: 1 if the string is a palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len;

	len = _strlen_recursion(s);
	return (check_palindrome(s, 0, len - 1));
}
