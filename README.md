# Welcome to My Printf

---

## Task

The goal of this project is to recreate a simplified version of the standard C `printf` function. The function must handle different format specifiers and display formatted output in the terminal.

## Description

The project implements a custom `my_printf` function in C using variadic arguments.

It supports the following format specifiers:
* `%d`: Prints a signed decimal integer.
* `%i`: Prints a signed decimal integer.
* `%o`: Prints an unsigned octal integer.
* `%u`: Prints an unsigned decimal integer.
* `%x`: Prints an unsigned hexadecimal integer in lowercase.
* `%c`: Prints a character.
* `%s`: Prints a string.
* `%p`: Prints a pointer address.
* `%%`: Prints a literal percent sign (`%`).

The function uses the `write` system call to display output and returns the number of characters printed.

## Installation

Clone the repository and navigate to the project directory.

Compile the program using the provided Makefile:
```bash
make
```

To remove the generated object files:
```bash
make clean
```

To remove all generated files, including the executable:
```bash
make fclean
```

To clean and recompile the project:
```bash
make re
```

## Usage

Run the compiled executable:
```bash
./my_printf
```

The program demonstrates the supported format specifiers. You can modify `main.c` to test different values and format specifiers.

Example:
```c
my_printf("Number: %d, Character: %c, String: %s\n", 42, 'A', "Hello");
```

Expected output:
```text
Number: 42, Character: A, String: Hello
```

### The Core Team

<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>