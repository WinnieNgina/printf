#include <stdarg.h>
#include "main.h"
/**
 * _printf - prints arguments on the standard output
 * @format: formatted string to be printed
 * Return: length of the string printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int num_printed = 0;
	int len;

	spec_t array[] = {
		{'c', handle_character}, {'s', handle_string},
		{'%', handle_modulus}, {'d', handle_decimal},
		{'i', handle_integer}
	};

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (array[i].identifier)
			{
				if (array[i].identifier == *format)
				{
					len = (array[i].function(args));
					num_printed += len;
				}
				i++;
			}
			i = 0;
		}
		else
		{
			_putchar(*format);
			num_printed++;
		}
		format++;
	}
	va_end(args);
	return (num_printed);
}
