#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"
/**
 * handle_wideString - prints the wideString on cmd
 * @args: wideString printed
 * Return: length of the wideString
 */
int handle_wideString(va_list args)
{
	char *widestring = va_arg(args, char *);
	/* printf("%s\n", widestring); */
	wchar_t *str = (wchar_t *)widestring;

	int len = _strlen(special_string(str));

	_puts(special_string(str));
	return (len);
}
/**
 * special_string - converts widestring to string
 * @wstr: widestring
 * Return: converted string
 */
char *special_string(wchar_t *wstr)
{
	size_t len = wcslen(wstr);
	unsigned long int i, j;
	char *str = malloc(len * 4 + 1);

	if (str == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	for (i = 0, j = 0; i < len; i++)
	{
		if (wstr[i] < 32 || wstr[i] >= 127)
		{
			sprintf(str + j, "\\x%02X", wstr[i]);
			j += 4;
		}
		else
		{
			str[j] = (char)wstr[i];
			j++;
		}
	}
	str[j] = '\0';
	return (str);
	}
