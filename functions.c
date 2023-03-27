#include <stdarg.h>
#include "main.h"
#include <stdio.h>
/**
 * _puts - prints a string
 * @str: string printed
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}
/**
 * handle_character - print a character
 * @args: the charcter printed
 * Return: 1 on success
 */
int handle_character(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
/**
 * _strlen - calculates the length of a string
 * @s: the string
 * Return: total legth of a string
 */
int _strlen(char *s)
{
	int i = 1, total = 0;
	char pl = s[0];

	while (pl != '\0')
	{
		total++;
		pl = s[i++];
	}
	return (total);
}
/**
 * handle_string - prints the string on cmd
 * @args: string printed
 * Return: length of the string
 */
int handle_string(va_list args)
{
	char *str = (va_arg(args, char*));
	int len;

	if (str == NULL)
	{
		str = "(null)";
	}
	len = _strlen(str);

	_puts(str);
	return (len);
}
/**
 * handle_modulus - prints modulus on standard output
 * @args: string printed
 *
 * Return: 1 on success
 */
int handle_modulus(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}
