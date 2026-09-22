#include "fonction.h"

int print_base(unsigned long nb, int base, char* digits) {
    int count = 0;
    int calc[sizeof(unsigned long) * 8];
    if ()

    return count;
}

int print_int(int d) {
    int count = 0;
    int calc[sizeof(int) * 8];
    if (d == 0) {
        char chiffre = d + '0';
        write(1, &chiffre, 1);
        count++;
    } else if (d > 0) {
        int j = 0;
        while (d != 0) {
            calc[j] = d % 10;
            d = d/10;
            j++;
        }
        while (j > 0 ){
            j--;
            char chiffre = calc[j] + '0';
            write(1, &chiffre, 1);
            count++;
        }
    } else {
        int j = 0;
        while (d != 0) {
            calc[j] = d % 10;
            d = d / 10;
            j++;
        }
        char negatif = '-';
        write(1, &negatif, 1);
        count++;
        while (j > 0 ){
            j--;
            char chiffre = calc[j] - calc[j] * 2 + '0';
            write(1, &chiffre, 1);
            count++;
        }
    }
    return count;
}

int print_octal(unsigned int o) {
    int count = 0;
    int calc[sizeof(unsigned int) * 8];
    if (o == 0) {
        char octal = o + '0';
        write(1, &octal, 1);
        count++;
    } else {
        int j = 0;
        while (o != 0) {
            calc[j] = o % 8;
            o = o/8;
            j++;
        }
        while (j > 0 ){
            j--;
            char octal = calc[j] + '0';
            write(1, &octal, 1);
            count++;
        }
    }
    return count;
}

int print_unsigned(unsigned int u) {
    int count = 0;
    int calc[sizeof(unsigned int) * 8];
    if (u == 0) {
        char unsign = u + '0';
        write(1, &unsign, 1);
        count++;
    } else {
        int j = 0;
        while (u != 0) {
            calc[j] = u % 10;
            u = u / 10;
            j++;
        }
        while (j > 0 ){
            j--;
            char unsign = calc[j] + '0';
            write(1, &unsign, 1);
            count++;
        }
    }
    return count;
}

int print_hexa(unsigned int x) {
    int count = 0;
    int calc[sizeof(unsigned int) * 8];
    char trad[] = "abcdef";
    if (x == 0) {
        char hexa = x + '0';
        write(1, &hexa, 1);
        count++;
    } else {
        int j = 0;
        while (x != 0) {
            calc[j] = x % 16;
            x = x / 16;
            j++;
        }
        while (j > 0 ){
            j--;
            if (calc[j] >= 10) {
                char hexa = trad[calc[j]-10];
                write(1, &hexa, 1);
                count++;
            } else {
                char hexa = calc[j] + '0';
                write(1, &hexa, 1);
                count++;
            }
        }
    }
    return count;
}

int print_char(char c) {
    int count = 0;
    write(1, &c, 1);
    count++;
    return count;
}

int print_string(char* s) {
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
    int count = 0;
    uintptr_t adresse = (uintptr_t)p;
    int calc[sizeof(uintptr_t) * 2];
    char trad[] = "abcdef";

    char zero = '0';
    char x = 'x';
    write(1, &zero, 1);
    write(1, &x, 1);
    count += 2;
    if (adresse == 0) {
        char hexa = adresse + '0';
        write(1, &hexa, 1);
        count++;
    } else {
        int j = 0;
        while (adresse != 0) {
            calc[j] = adresse % 16;
            adresse = adresse/16;
            j++;
        }
        while (j > 0 ){
            j--;
            if (calc[j] >= 10) {
                char hexa = trad[calc[j]-10];
                write(1, &hexa, 1);
                count++;
            } else {
                char hexa = calc[j] + '0';
                write(1, &hexa, 1);
                count++;
            }
        }
    }
    return count;
}

int print_pourcent(void) {
    int count = 0;
    char pourcent = '%';
    write(1, &pourcent, 1);
    count++;
    return count;
}