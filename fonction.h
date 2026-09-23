#ifndef FONCTION_H
#define FONCTION_H

#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

int my_printf(char* restrict format, ...);
int print_base(unsigned long nb, int base, const char* digits);
int print_int(int d);
int print_octal(unsigned int o);
int print_unsigned(unsigned int u);
int print_hexa(unsigned int x);
int print_char(char c);
int print_string(const char* s);
int print_pointeur(void* p);
int print_pourcent(void);

#endif