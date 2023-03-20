#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		/* Check if the letter is not 'q' or 'e' */
		if (letter != 'q' && letter != 'e')
		{
			/* Print the letter */
			putchar(letter);
		}
	}

	/* Print newline character */
	putchar('\n');

	return (0);
}
