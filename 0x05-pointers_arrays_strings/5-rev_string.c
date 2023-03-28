#include "main.h"

/**
 * rev_string - Reverses a string.
 * @s: The string to be reversed.
 */
void rev_string(char *s)
{
	int i, j;
	char temp;

	/* Find the length of the string */
	j = 0;
	while (s[j] != '\0')
	{
		j++;
	}

	/* Swap characters from both ends of the string towards the middle */
	i = 0;
	j = j - 1;
	while (i < j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
