#include <stdarg.h>
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * handle_decimal - prints the decimal on cmd
 * @args: decimal printed
 * Return: length of the decimal
 */
int handle_decimal(va_list args)
{
	int strInt = va_arg(args, int);
	int len = print_number(strInt);

	return (len);
}

/**
 * handle_integer - prints the integer on cmd
 * @args: integer printed
 * Return: length of the integer
 */
int handle_integer(va_list args)
{
	int strInt = va_arg(args, int);
	int len = print_number(strInt);

	return (len);
}

/**
 * print_number - prints the integer on cmd
 * @n: integer printed
 * Return: length of the integer
 */
int print_number(int n)
{
	unsigned int n1;
	int count = 0;

	if (n < 0)
	{
		n1 = -n;
		_putchar('-');
		count++;
	}
	else
	{
		n1 = n;
	}

	if (n1 / 10)
	{
		count += print_number(n1 / 10);
	}

	_putchar((n1 % 10) + '0');
	count++;

	return (count);
}

