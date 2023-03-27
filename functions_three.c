#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * handle_binary - converts decimal to binary
 * @args: decimal numbers
 * Return: length of the string
 */
int handle_binary(va_list args)
{
	int binary = va_arg(args, int);
	char *binary_str;
	int len;

	if (binary < 0)
	{
		return (-1);
	}
	binary_str = decimal_to_binary(binary);
	len = _strlen(binary_str);

	_puts(binary_str);
	return (len);
}
/**
 * decimal_to_binary - converts decimal to binary
 * @decimal: number converted to binary
 * Return: Returns the binary of a decimal
 */
char *decimal_to_binary(int decimal)
{
	int quotient, length, index, i;
    /*allocate memory for binary string*/
	char *binary = (char *)malloc(33 * sizeof(char));

	if (binary == NULL)
	{
		exit(EXIT_FAILURE);
	}
	/*convert decimal to binary*/
	quotient = decimal;
	index = 0;

	do {
		binary[index++] = (quotient % 2) + '0';
		quotient /= 2;
	}

	while (quotient > 0);
	binary[index] = '\0';
	/*reverse binary string*/
	length = _strlen(binary);

	for (i = 0; i < length / 2; i++)
	{
		char temp = binary[i];

		binary[i] = binary[length - i - 1];
		binary[length - i - 1] = temp;
	}
	return (binary);
}
