NAME = libmyprintf.a
SRC = my_printf.c fonction.c
OBJ = $(SRC:.c =.o)

all: $(NAME)

$(NAME): $(OBJ)
    ar rc $(NAME) $(OBJ)

%.o: %.c
    gcc -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY all clean fclean re