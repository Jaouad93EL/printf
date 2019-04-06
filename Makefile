##
## ETNA PROJECT, 18/01/2019 by elhorm_j
## makefile
## File description:
##      [...]
##

NAME	= libmy_printf_`uname -m`-`uname -s`
CFLAGS = -Wextra -Wall -Werror

SRC		= \
		display_float.c \
		my_printf.c \
		display_number.c \
		display_putstr.c \
		get_putnbr.c \
		my_getnbr.c \

OBJ 	= $(SRC:.c=.o)

all: my_printf_static my_printf_dynamic install

my_printf_static: $(OBJ)
		gcc $(CFLAGS) -c $(SRC)
		ar rc $(NAME).a $(OBJ)

my_printf_dynamic: $(OBJ)
		gcc $(CFLAGS) -fPIC -shared -o $(NAME).so $(SRC)

install:
	sudo cp $(NAME).so /usr/lib

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME).a  $(NAME).so

re: fclean all

.PHONY: my_printf_static my_printf_dynamic all clean fclean re