#include "main.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/**
 * count_words - count number of words in a string
 * @str: the string to count words in
 *
 * Return: number of words in str
 */
int count_words(char *str)
{
	int count = 0, i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: the string to split
 *
 * Return: pointer to an array of strings, or NULL on failure
 */
char **strtow(char *str)
{
	char **words;
	int i, j, k, n;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	n = count_words(str);
		if (n == 0)
			return (NULL);

		words = malloc((n + 1) * sizeof(char *));
		if (words == NULL)
			return (NULL);

		for (i = 0, j = 0; j < n; j++)
		{
			while (str[i] == ' ')
				i++;
			k = i;
			while (str[k] != ' ' && str[k] != '\0')
				k++;
			words[j] = malloc((k - i + 1) * sizeof(char));
			if (words[j] == NULL)
			{
				for (j--; j >= 0; j--)
					free(words[j]);
				free(words);
				return (NULL);
			}
			for (; i < k; i++)
				words[j][i - j] = str[i];
			words[j][i - j] = '\0';
		}
		words[j] = NULL;
		return (words);
}
