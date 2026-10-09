# Welcome to My Printf

---

## Task

The goal of this project is to recreate a simplified version of the standard C `printf()` function.
The challenge is to implement a variadic function that reads a format string, identifies format specifiers, retrieves the corresponding arguments and prints the formatted output to the standard output.

## Description

This project implements a custom `my_printf()` function in C using variadic arguments.
The function processes a format string character by character. When it encounters a format specifier, it calls the corresponding function through a dispatch table.

The following format specifiers are supported:
* `%d` and `%i`: print signed decimal integers.
* `%o`: print unsigned integers in octal format.
* `%u`: print unsigned decimal integers.
* `%x`: print unsigned integers in lowercase hexadecimal format.
* `%c`: print a character.
* `%s`: print a string.
* `%p`: print a pointer address in hexadecimal format, prefixed with `0x`.
* `%%`: print a literal percent sign.

The project also includes a helper function, `print_base()`, to convert and print numbers in different bases.
The function returns the number of characters printed.

## Installation

Compile the project using the provided Makefile:
```bash
make
```

On Windows with MinGW, you can use:
```bash
mingw32-make
```

To remove the generated object files:
```bash
make clean
```

To remove all generated files, including the executable:
```bash
make fclean
```

To rebuild the project from scratch:
```bash
make re
```

## Usage

Run the compiled program:
```bash
./my_printf
```

The current example in `main.c` prints a string and an integer:
```c
my_printf("Hello %s, you are %d!", "Boob", 31);
```

Output:
```text
Hello Boob, you are 31!
```

You can also use `my_printf()` with other supported format specifiers:
```c
my_printf("Character: %c\n", 'A');
my_printf("Decimal: %d\n", 42);
my_printf("Octal: %o\n", 42);
my_printf("Unsigned: %u\n", 42);
my_printf("Hexadecimal: %x\n", 42);
my_printf("String: %s\n", "Hello");
my_printf("Pointer: %p\n", (void*)main);
my_printf("Progress: 100%%\n");
```

### The Core Team

Made at Qwasar SV -- Software Engineering School