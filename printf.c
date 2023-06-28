#include <stdio.h>
#include <stdarg.h>

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
}

