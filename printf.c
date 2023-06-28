<<<<<<< HEAD
#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
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
=======
#include <stdio.h>
#include <stdarg.h>
#include <main.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; // Counter for characters printed

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; // Move past '%'

            // Handle conversion specifiers
            switch (*format)
            {
                case 'c':
                {
                    // Print a character
                    int c = va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }

                case 's':
                {
                    // Print a string
                    char *s = va_arg(args, char *);
                    while (*s != '\0')
                    {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }

                case '%':
                {
                    // Print a literal '%'
                    putchar('%');
                    count++;
                    break;
                }

                default:
                    // Ignore unknown format specifiers
                    break;
            }
        }
        else
        {
            // Print regular characters
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

int main()
{
    _printf("I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life.\n");
    _printf("My favorite number is %d.\n", 42);
    _printf("The character %c is cool.\n", 'A');
    _printf("This is a %s.\n", "test");

    return 0;
>>>>>>> 7ba56287df87c0da50ad753302bbb5a029edc632
}

