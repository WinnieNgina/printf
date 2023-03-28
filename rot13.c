#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_ROT13 - prints the encoded string on cmd
 * @args: string to be encoded
 * Return: length of the encoded string
 */
int handle_ROT13(va_list args)
{
	char *str = (va_arg(args, char*));
	int len;
	char *rot;

	if (str == NULL)
	{
		str = "(AHYY)";
	}
	rot = rot13(str);
	len = _strlen(rot);

	_puts(rot);
	return (len);
}

/**
 * rot13 - Encode a string to rot13
 * @str: string to encode
 * Return: pointer to encoded string
 */
char *rot13(char *str)
{
	size_t len = strlen(str);
	size_t i;
	char *result = malloc(len + 1);

	for (i = 0; i < len; i++)
	{
		char c = str[i];

		if (c >= 'A' && c <= 'Z')
		{
			result[i] = ((c - 'A') + 13) % 26 + 'A';
		}
		else if (c >= 'a' && c <= 'z')
		{
			result[i] = ((c - 'a') + 13) % 26 + 'a';
		}
		else
		{
			result[i] = c;
		}
	}

	result[len] = '\0';
	return (result);
}






