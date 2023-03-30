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
	int i, j;
	char leet[] = "aAeEoOtTlL";
	char nums[] = "4433007711";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (str[i] == leet[j])
			{
				str[i] = nums[j];
				break;
			}
		}
	}
	str[i] = '\0';

	return str;
}
