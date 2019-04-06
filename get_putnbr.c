/*
** ETNA PROJECT, 16/01/2019 by elhorm_j
** functionThree.c
** File description:
**      [...]
*/

#include "my_printf.h"

void my_print_nbr(va_list arg, parse_t *p)
{
    my_putnbr(va_arg(arg, int), p);
}

void my_print_octal(va_list arg, parse_t *p)
{
    my_putnbr_octal(va_arg(arg, unsigned int), p);
}

void my_print_hexa(va_list arg, int c, parse_t *p)
{
    my_putnbr_hexa(va_arg(arg, unsigned int), c, p);
}

void my_print_unsigned(va_list arg, parse_t *p)
{
    my_putnbr_unsigned(va_arg(arg, unsigned int), p);
}

int my_nbrlen(int n)
{
    int i = 0;

    if (n == 0)
        return 1;
    if (n < 0) {
        n *= -1;
        ++i;
    }
    while (n != 0) {
        n = (n / 10);
        ++i;
    }
    return (i);
}
