#include <stdarg.h>
#include "fonction.h"

int my_printf(char * restrict format, ...) {
    va_list args;
    
    va_start(args, format);

    int count = 0;
    int i = 0;

    if(format == NULL) {
        return 0;
    }
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i ++;

            if (format[i] == 'd' || format[i] == 'i') {
                count += print_int(va_arg(args, int));

            } else if (format[i] == 'o') {
                count += print_octal(va_arg(args, unsigned int));

            } else if (format[i] == 'u') {
                count += print_unsigned(va_arg(args, unsigned int));

            } else if (format[i] == 'x') {
                count += print_hexa(va_arg(args, unsigned int));

            } else if (format[i] == 'c') {
                count += print_char((char)va_arg(args, int));

            } else if (format[i] == 's') {
                count += print_string(va_arg(args, char*));

            } else if (format[i] == 'p') {
                count += print_pointeur(va_arg(args, void*));

            } else if (format[i] == '%') {
                count += print_pourcent();

            }
            i++;
        } else {
            write(1, &format[i], 1);
            count++;
            i++;
        }
    }

    va_end(args);
    return count;
}