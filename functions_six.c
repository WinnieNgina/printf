#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * handle_pointer - converts decimal to binary
 * @args: address to values
 * Return: length of the address string
 */
int handle_pointer(va_list args)
{
	void *ptr = va_arg(args, void *);
	char hex[16];
	unsigned long num = (unsigned long) ptr;
	int i, j, leading_zeros = 1;
	int count = 0;

	if (ptr == NULL)
	{
		return (-1);
	}

	_putchar('0');
	_putchar('x');
	count += 2;

	for (i = 0; i < 16; i++)
	{
		hex[i] = num & 0xf;
		num >>= 4;
	}

	for (j = i - 1; j >= 0; j--)
	{
		char c = hex[j] < 10 ? '0' + hex[j] : 'a' + hex[j] - 10;

		if (hex[j] != 0 || !leading_zeros)
		{
			_putchar(c);
			count++;
			leading_zeros = 0;
		}
	}
	return (count);
}
