#include "main.h"
#include <stdarg.h>
#include <stddef.h>
/**
 * handle_reverse_str - prints the string on cmd in reverse
 * @args: string printed
 * Return: length of the string
 */
int handle_reverse_str(va_list args)
{
	char *str = (va_arg(args, char*));
	int len;

	if (str == NULL)
	{
		str = "(null)";
	}
	len = _strlen(str);

	print_rev(str);
	return (len);
}
/**
 * print_rev - prints a string, in reverse
 * fcount is to first count to end, n is to count back
 * @s: str input
 * Return: string in reverse
 */
void print_rev(char *s)
{
	int fcount = 0;
	int i, n;

	for (i = 0; s[i] != '\0'; i++)
	{
		fcount++;
	}

	for (n = (fcount - 1); n >= 0; n--)
	{
		_putchar(s[n]);
	}
}
