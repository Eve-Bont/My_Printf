#include "fonction.h"

// mingw32-make ou make clean ou make fclean ou make re
// utiliser gcc -Wall -Wextra -Werror main.c -L. -lmyprintf -o test.exe
// puis ./test.exe

int main(void)
{
    my_printf("Hello %s, you are %d!", "Boob", 31);

    return 0;
}