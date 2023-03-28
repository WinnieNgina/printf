#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/**
 * decimalToHexadecimal - converts decimal to hexadecimal
 * @decimal: decimal converted
 * Return: hexadecimal string
 */
char *decimalToHexadecimal(int decimal)
	{
		char *hexadecimal = (char *) malloc(sizeof(char) * 100);
		int remainder, quotient;
		int i = 0;
		int length, j;
		char temp;

		if (hexadecimal == NULL)
		{
			return (NULL);
		}
		while (decimal > 0)
		{
			remainder = decimal % 16;
			quotient = decimal / 16;
			if (remainder < 10)
			{
				hexadecimal[i] = remainder + '0';
			}
			else
			{
				hexadecimal[i] = remainder + 'A' - 10;
			}
			i++;
			decimal = quotient;
		}
		if (i == 0)
		{
			hexadecimal[i] = '0';
			i++;
		}

		hexadecimal[i] = '\0';
		length = strlen(hexadecimal);
		for (j = 0; j < length / 2; j++)
		{
			temp = hexadecimal[j];
			hexadecimal[j] = hexadecimal[length - j - 1];
			hexadecimal[length - j - 1] = temp;
		}
		return (hexadecimal);
	}
/**
 * toLower - converts uppercase to lowercase
 * @str: string converted
 * Return: lowercase string
 */
char *toLower(char *str)
{
	int length = strlen(str);
	char *lower = (char *) malloc(sizeof(char) * (length + 1));
	int i;

	if (lower == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < length; i++)
	{
		lower[i] = tolower(str[i]);
	}

	lower[length] = '\0';

	return (lower);
}
