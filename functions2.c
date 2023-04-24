#include "main.h"
/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[], int flags,
		int width, int size, int precision)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);

	n = convert_size_unsgnd(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 10) + '0';
		n /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, size, precision));
}
/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[], int flags,
		int width, int size, int precision)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(width);
	n = convert_size_unsgnd(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = (n % 8) + '0';
		n /= 8;
	}
	if (flags & F_HASH && init_n != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, size, precision));
}
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[], int flags,
		int width, int size, int precision)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, size, precision));
}
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[], int flags,
		int width, int size, int precision)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, size, precision));
}
/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map[], char buffer[], int flags,
		char flag_ch, int width, int size, int precision)
{
	int i = BUFF_SIZE - 2;
	unsigned long int n = va_arg(types, unsigned long int);
	unsigned long int init_n = n;

	UNUSED(width);
	n = convert_size_unsgnd(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buffer[i--] = map[n % 16];
		n /= 16;
	}
	if (flags & F_HASH && init_n != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, size, precision));
}
