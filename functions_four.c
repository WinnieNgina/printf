#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * handle_octal - prints the octal on cmd
 * @args: octal printed
 * Return: length of the octal
 */
int handle_octal(va_list args)
{
	int octal = va_arg(args, int);
	char *strOctal = decimalToOctal(octal);
	int len = _strlen(strOctal);

	_puts(strOctal);
	return (len);
}
/**
 * handle_unsigned - prints the unsigned integer on cmd
 * @args: unsigned integer printed
 * Return: length of the unsigned integer
 */
int handle_unsigned(va_list args)
{
	int strInt = va_arg(args, int);
	int len;

	if (strInt < 0)
	{
		return (-1);
	}
	len = print_number(strInt);

	return (len);
}
/**
 * handle_hex_low - prints the hexadecimal on cmd
 * @args: hexadecimal printed
 * Return: length of the hexadecimal
 */
int handle_hex_low(va_list args)
{
	int hexa = va_arg(args, int);
	char *strHexa = toLower(decimalToHexadecimal(hexa));
	int len = _strlen(strHexa);

	_puts(strHexa);
	return (len);

}
/**
 * handle_hex_up - prints the hexadecimal on cmd
 * @args: hexadecimal printed
 * Return: length of the hexadecimal
 */
int handle_hex_up(va_list args)
{
	int hexa = va_arg(args, int);
	char *strHexa = decimalToHexadecimal(hexa);
	int len = _strlen(strHexa);

	_puts(strHexa);
	
	return (len);

}
/**
 * decimalToOctal - converts decimal to ocal
 * @decimal: decimal converted
 * Return: octal string
 */
char *decimalToOctal(int decimal)
	{
		char *octal = (char *) malloc(sizeof(char) * 100);
		int length = strlen(octal);
		char temp;
		int remainder, quotient;
		int i;
		int j;

		if (octal == NULL)
				{
			return (NULL);
		}

		i = 0;

		while (decimal > 0)
		{
			remainder = decimal % 8;
			quotient = decimal / 8;
			octal[i] = remainder + '0';
			i++;
			decimal = quotient;
		}

		if (i == 0)
		{
			octal[i] = '0';
			i++;
		}

		octal[i] = '\0';

		length = strlen(octal);
		for (j = 0; j < length / 2; j++)
		{
			temp = octal[j];
			octal[j] = octal[length - j - 1];
			octal[length - j - 1] = temp;
		}

		return (octal);
	}
