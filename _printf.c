#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function with output.
 * @format: format.
 * Return: Printed chars.
 */

int  _printf(const char *format, ...)
{
	int x, printed = 0, p_chars = 0, flg, width, prc, size, buff_i = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[x] != '%')
		{
			buffer[buff_i++] = format[x];
			if (buff_i == BUFF_SIZE)
				print_buffer(buffer, &buff_i);
			p_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_i);
			flg = get_flags(format, &x);
			width = get_width(format, &x, list);
			prc = get_precision(format, &x, list);
			size = get_size(format, &x);
			++x;
			printed = handle_print(format, &x, list, buff,
					flags, width, size, precision);
			if (printed == -1)
				return (-1);
			p_chars += printed;
		}
	}
	print_buffer(buffer, &buff_i);
	va_end(list);
	return (p_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
