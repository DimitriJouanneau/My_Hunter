##
## EPITECH PROJECT, 2025
## makefile
## File description:
## makefile
##

CC = epiclang

SRC = my_putchar.c \
	my_put_number.c \
	my_put_str.c \
	check_specifiers.c \
	check_specifiers_two.c \
	convert_exadecimal.c \
	convert_octal.c \
	my_printf.c \
	my_scientific_notation.c \
	print_width.c \
    check_specifiers_three.c \
	my_put_float.c \
    my_unsigned_number.c

OBJ = $(SRC:.c=.o)

NAME_LIB = libmy.a

NAME_HEADER = my_printf.h

all: $(NAME_LIB)

$(NAME_LIB): $(OBJ)
	ar rs $(NAME_LIB) $(OBJ)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME_LIB)

re: fclean all

unit_tests: $(NAME_LIB)
	$(CC) -o unit_tests $(SRC) tests/tests_my_printf.c --coverage -lcriterion -Wl,--wrap=malloc

tests_run: unit_tests
	./unit_tests
