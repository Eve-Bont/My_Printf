#include "fonction.h"

// mingw32-make ou make clean ou make fclean ou make re
// utiliser gcc -Wall -Wextra -Werror main.c -L. -lmyprintf -o test.exe
// puis ./test.exe

int main(void)
{
    int n = my_printf("Hello %d\n", 42);
    my_printf("Retour = %d\n", n);

    return 0;
}