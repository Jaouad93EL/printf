/*
** ETNA PROJECT, 16/01/2019 by elhorm_j
** functionFour.c
** File description:
**      [...]
*/

#include "my_printf.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str, parse_t *p)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        p->length += 1;
        ++i;
    }
}

void my_put_one(int c)
{
    write(1, &c, 1);
}

void my_print_char(va_list arg, parse_t *p)
{
    p->length += 1;
    my_put_one(va_arg(arg, int));
}

void my_print_str(va_list arg, parse_t *p)
{
    my_putstr(va_arg(arg, char *), p);
}
