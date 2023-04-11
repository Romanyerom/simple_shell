#include <stdlib.h>
#include "main.h"

/**
 * strtow - Splits a string into words.
 * @str: The string to split.
 *
 * Return: A pointer to an array of strings (words), or NULL if str == NULL or
 *         if memory allocation fails.
 */
char **strtow(char *str)
{
char **words;
int words_count = 0;
int i, j, k;

if (str == NULL || str[0] == '\0')
return (NULL);

 /* Count the number of words in the string */
for (i = 0; str[i] != '\0'; i++)
{
if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
words_count++;
}
/* Allocate memory for the array of words */
words = malloc(sizeof(char *) * (words_count + 1));

if (words == NULL)
return (NULL);
/* Extract each word from the string */
for (i = 0, j = 0; str[i] != '\0'; j++)
{
/* Skip over any leading whitespace */
while (str[i] == ' ')
i++;

/* Find the end of the current word */
for (k = i; str[k] != ' ' && str[k] != '\0'; k++)
;

/* Allocate memory for the current word */
words[j] = malloc(sizeof(char) * (k - i + 1));

if (words[j] == NULL)
{
/* Free previously allocated memory if allocation fails */
for (k = 0; k < j; k++)
free(words[k]);
free(words);
return (NULL);
}
/* Copy the current word into the allocated memory */
for (k = i; str[k] != ' ' && str[k] != '\0'; k++)
words[j][k - i] = str[k];
words[j][k - i] = '\0';
i = k + 1; /* Move i to the next word */
}
words[j] = NULL; /* Terminate the array with a NULL pointer */
return (words);
}
