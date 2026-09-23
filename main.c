#include "fonction.h"

int main(void)
{
    int x = 42;

    my_printf("Bonjour !\n");
    my_printf("Nombre : %d\n", 123);
    my_printf("Négatif : %d\n", -42);
    my_printf("Octal : %o\n", 64);
    my_printf("Hexa : %x\n", 255);
    my_printf("Unsigned : %u\n", 4294967295U);
    my_printf("Caractère : %c\n", 'A');
    my_printf("Chaîne : %s\n", "Hello");
    my_printf("NULL : %s\n", NULL);
    my_printf("Pointeur : %p\n", &x);
    my_printf("Pourcent : %%\n");

    return 0;
}