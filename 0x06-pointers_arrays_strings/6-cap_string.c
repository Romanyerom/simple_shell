#include "main.h"
#include <stdio.h>

/**
 * cap_string - Capitalizes all words of a string.
 * @s: A pointer to the string to be capitalized.
 *
 * Return: A pointer to the capitalized string.
 */
char *cap_string(char *s)
{
	char *p = s;
	int cap = 1;

	while (*p)
	{
		if (cap && *p >= 'a' && *p <= 'z')
			*p -= 32;
		cap = (*p == ' ' || *p == '\t' || *p == '\n' ||
			*p == ',' || *p == ';' || *p == '.' ||
			*p == '!' || *p == '?' || *p == '"' ||
			*p == '(' || *p == ')' || *p == '{' ||
			*p == '}');
		p++;
	}

	return (s);
}
