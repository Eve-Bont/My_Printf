#include "fonction.h"

const t_dispatch dispatch[] = {
    {'d', print_int},
    {'i', print_int},
    {'o', print_octal},
    {'u', print_unsigned},
    {'x', print_hexa},
    {'c', print_char},
    {'s', print_string},
    {'p', print_pointeur},
    {'%', print_pourcent}
};

int my_printf(char* restrict format, ...) {
    va_list args;

    if(format == NULL) {
        return 0;
    }

    va_start(args, format);
    int count = 0;
    int i = 0;
    
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            
            if (format[i] == '\0') {
                va_end(args);
                return count;
            }

            for (size_t j = 0; j < sizeof(dispatch) / sizeof(dispatch[0]); j++) {
                if (dispatch[j].specifier == format[i]) {
                    count += dispatch[j].fonction(args);
                    break;
                }
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