#include "main.h"
#include <stdio.h>

/**
 * leet - encodes a string into 1337
 * @str: string to encode
 *
 * Return: pointer to resulting string
 */

char *leet(char *str)
{
	char *leetspeak = str;
	char *letters = "aAeEoOtTlL";
	char *numbers = "44330711";
	int i, j;

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; letters[j] != '\0'; j++)
		{
			if (str[i] == letters[j])
			{
				str[i] = numbers[j];
			}
		}
	}

	return (leetspeak);
}
