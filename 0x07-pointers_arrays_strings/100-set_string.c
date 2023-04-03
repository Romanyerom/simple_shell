#include "main.h"
#include <stdio.h>

/**
 * set_string - sets the value of a pointer to a char
 *
 * @s: pointer to a pointer to a char
 * @to: pointer to a char
 *
 * Description: This function sets the value of a pointer to a char.
 * It takes a pointer to a pointer to a char and a pointer to a char
 * as arguments. The value of the pointer pointed to by `s` is set
 * to the same location as `to`.
 */
void set_string(char **s, char *to)
{
	*s = to;
}
