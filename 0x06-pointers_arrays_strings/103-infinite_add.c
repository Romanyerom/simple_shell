#include <stdio.h>
#include <string.h>

/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: buffer to store result
 * @size_r: size of buffer
 *
 * Return: pointer to result, or 0 if result cannot be stored in r
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = strlen(n1);
	int len2 = strlen(n2);
	int max_len = (len1 > len2) ? len1 : len2;
	int carry = 0;
	int sum = 0;

	/* Check if result can be stored in r */
	if (max_len + 1 > size_r)
		return (0);

	/* Add digits from right to left */
	for (int i = 0; i < max_len; i++)
	{
		int d1 = (i < len1) ? n1[len1 - 1 - i] - '0' : 0;
		int d2 = (i < len2) ? n2[len2 - 1 - i] - '0' : 0;
		sum = d1 + d2 + carry;
		carry = sum / 10;
		r[max_len - i - 1] = (sum % 10) + '0';
	}

	/* Add final carry if there is one */
	if (carry > 0)
	{
		if (max_len + 1 > size_r)
			return (0);
		r[max_len] = carry + '0';
		r[max_len + 1] = '\0';
	}
	else
	{
		r[max_len] = '\0';
	}

	return (r);
}
