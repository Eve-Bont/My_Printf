#include "fonction.h"

int print_base(unsigned long nb, int base, const char* digits) {
    int count = 0;
    int calc[sizeof(unsigned long) * 8];
    
    if (nb == 0) {
        char l = '0';
        write(1, &l, 1);
        count++;
    } else {
        int j = 0;
        while (nb != 0) {
            calc[j] = nb % base;
            nb = nb / base;
            j++;
        }
        while (j > 0) {
            j--;
            char final = digits[calc[j]];
            write(1, &final, 1);
            count++;
        }
    }
    return count;
}

int print_int(int d) {
    if (d >= 0) {
        return print_base(d, 10, "0123456789");
    } else {
        char negatif = '-';
        write(1, &negatif, 1);
        return 1 + print_base(-((long)d), 10, "0123456789");
    }
}

int print_octal(unsigned int o) {
    return print_base(o, 8, "01234567");
}

int print_unsigned(unsigned int u) {
    return print_base(u, 10, "0123456789");
}

int print_hexa(unsigned int x) {
    return print_base(x, 16, "0123456789abcdef");
}

int print_char(char c) {
    write(1, &c, 1);
    return 1;
}

int print_string(const char* s) {
    int count = 0;
    int j = 0;
    if(s == NULL) {
        write(1, "(null)", 6);
        return 6;
    }
    while (s[j] != '\0') {
        write(1, &s[j], 1);
        count++;
        j++;
    }
    return count;
}

int print_pointeur(void* p) {
    uintptr_t adresse = (uintptr_t)p;

    char zero = '0';
    char x = 'x';
    write(1, &zero, 1);
    write(1, &x, 1);
    
    return 2 + print_base(adresse, 16, "0123456789abcdef");
}

int print_pourcent(void) {
    char pourcent = '%';
    write(1, &pourcent, 1);
    return 1;
}