#ifndef FONCTION_H
#define FONCTION_H

#include <unistd.h>
#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

typedef struct s_dispatch {
    char specifier;
    int (*fonction)(va_list);
} t_dispatch;

int my_printf(char* restrict format, ...);
int print_base(unsigned long nb, int base, const char* digits);
int print_int(va_list args);
int print_octal(va_list args);
int print_unsigned(va_list args);
int print_hexa(va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_pointeur(va_list args);
int print_pourcent(va_list args);

#endif