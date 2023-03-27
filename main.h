#ifndef MAIN_H_
#define MAIN_H_
#include <stdarg.h>

int _printf(const char *format, ...);
/**
 * struct specifiers_list - struct including variables for format specifiers
 * @identifier: represents %
 * @function: poiter to a function with va_list data type
 */
typedef struct specifiers_list
{
	char identifier;
	int (*function)(va_list);
} spec_t;
int handle_string(va_list);
int handle_modulus(va_list);
int handle_character(va_list);
int handle_decimal(va_list);
int handle_integer(va_list);
int handle_binary(va_list);
void _puts(char *str);
int _strlen(char *s);
int _putchar(char c);
int print_number(int n);
char *decimal_to_binary(int decimal);

#endif
