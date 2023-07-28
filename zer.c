#include "shell.h"

/**
 * split_string - splits a string into words using multiple delimiters
 * @str: the input string
 * @delimiters: the delimiters used to split the string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **split_string(char *str, char *delimiters)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	if (!delimiters)
		delimiters = " ";

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!is_delimiter(str[i], delimiters) &&
				(is_delimiter(str[i + 1], delimiters) || str[i + 1] == '\0'))
		{
			numwords++;
		}
	}

	if (numwords == 0)
		return (NULL);

	s = malloc((numwords + 1) * sizeof(char *));
	if (!s)
		return (NULL);

	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delimiter(str[i], delimiters);
				i++;

				k = 0;
				while (!is_delimiter(str[i + k], delimiters) && str[i + k] != '\0')
				k++;
				s[j] = malloc((k + 1) * sizeof(char));

				if (!s[j]
					for (k = 0; k < j; k++)
					free(s[k]);
					free(s);
					return (NULL);

					for (m = 0; m < k; m++)
					s[j][m] = str[i++];
					s[j][m] = '\0';
					}

					s[j] = NULL;

					return (s);
					}

/**
 * split_string_single_delim - splits a string into words using a single delimiter
 * @str: the input string
 * @delimiter: the delimiter used to split the string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **split_string_single_delim(char *str, char delimiter)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] != delimiter && str[i + 1] == delimiter)
				(str[i] != delimiter && str[i + 1] == '\0')
				str[i + 1] == delimiter)
		{
			numwords++;
		}
	}

	if (numwords == 0)
		return (NULL);

	s = malloc((numwords + 1) * sizeof(char *));

	if (!s)
		return (NULL);

	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == delimiter)
			i++;

		k = 0;

		while (str[i + k] != delimiter && str[i + k] != '\0')
			k++;

		s[j] = malloc((k + 1) * sizeof(char));

		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
            return (NULL);
		}

		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = '\0';
	}

	s[j] = NULL;

	return (s);
}
