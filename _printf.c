#include <stdarg.h>
#include "main.h"
#include <stddef.h>
/**
 * _printf - prints arguments on the standard output
 * @format: formatted string to be printed
 * Return: length of the string printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len, i = 0, num_printed = 0;

	spec_t array[] = {
		{'c', handle_character}, {'s', handle_string}, {'%', handle_modulus},
		{'d', handle_decimal}, {'i', handle_integer}, {'b', handle_binary},
		{'o', handle_octal}, {'u', handle_unsigned}, {'x', handle_hex_low},
		{'X', handle_hex_up}, {'S', handle_wideString}, {'p', handle_pointer},
		{'r', handle_reverse_str}, {'R', handle_ROT13}
	};
	if (format == NULL)
		return (-1);
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
