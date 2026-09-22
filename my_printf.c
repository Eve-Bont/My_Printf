#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int my_printf(char * restrict format, ...) {
    va_list args;
    
    va_start(args, format);

    int count = 0;
    int i = 0;
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i ++;

            if (format[i] == 'd' || format[i] == 'i') {
                int d = va_arg(args, int);
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

            } else if (format[i] == 'o') {
                unsigned int o = va_arg(args, unsigned int);
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

            } else if (format[i] == 'u') {
                unsigned int u = va_arg(args, unsigned int);
                int calc[sizeof(unsigned int) * 8];

                if (u == 0) {
                    char unsign = u + '0';
                    write(1, &unsign, 1);
                    count++;

                } else {
                    int j = 0;
                    while (u != 0) {
                        calc[j] = u % 10;
                        u = u/10;
                        j++;
                    }
                    while (j > 0 ){
                        j--;
                        char unsign = calc[j] + '0';
                        write(1, &unsign, 1);
                        count++;
                    }
                }

            } else if (format[i] == 'x') {
                unsigned int x = va_arg(args, unsigned int);
                int calc[sizeof(unsigned int) * 8];
                char trad[] = {"abcdef"};

                if (x == 0) {
                    char hexa = x + '0';
                    write(1, &hexa, 1);
                    count++;

                } else {
                    int j = 0;
                    while (x != 0) {
                        calc[j] = x % 16;
                        x = x/16;
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

            } else if (format[i] == 'c') {
                char c = (char)va_arg(args, int);
                write(1, &c, 1);
                count++;

            } else if (format[i] == 's') {
                char* s = va_arg(args, char*);
                int j = 0;
                while (s[j] != '\0') {
                    write(1, &s[j], 1);
                    count++;
                    j++;
                }

            } else if (format[i] == 'p') {
                void* p = va_arg(args, void*);
                uintptr_t adresse = (uintptr_t)p;
                int calc[sizeof(uintptr_t) * 2];
                char trad[] = {"abcdef"};

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

            } else if (format[i] == '%') {
                char pourcent = '%';
                write(1, &pourcent, 1);
                count++;

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