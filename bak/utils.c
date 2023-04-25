#include "main.h"

/**
 *is_printable - check if a character is printable
 *@c: character to be checked.
 *Return: 1 good, 0 else
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 *append_hexa_code - Append Asci in hex format to buffer
 *@buffer: array of characters
 *@i: index for starting appending.
 *@ascii_code: Ascii code
 *Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";
	/*The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 *is_digit - check if it's a digit
 *@c: character to be checked
 *Return: 1 good, 0 else
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 *convert_size_number - convert number to a preset size
 *@num: number to be converted.
 *@size: size.
 *Return: converted number
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short) num);

	return ((int) num);
}

/**
 *convert_size_unsgnd - convert to a preset size
 *@num: number to be converted
 *@size: size
 *Return: converted number
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short) num);

	return ((unsigned int) num);
}
