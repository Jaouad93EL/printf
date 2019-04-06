/*
** ETNA PROJECT, 16/01/2019 by elhorm_j
** functionTwo.c
** File description:
**      [...]
*/

#include "my_printf.h"

void my_print_float(va_list arg, parse_t *p)
{
    my_float(va_arg(arg, double), 6, p);
}

void my_print_prec(va_list arg, parse_t *p)
{
    char *getnb = NULL;
    int i = 0;
    int j = 0;
    int k = p->index + 1;

    while (p->str[++p->index] >= '0' && p->str[p->index] <= '9')
        ++i;
    getnb = malloc(sizeof(char) * i);
    if (p->str[p->index] == 'f') {
        while (i > 0) {
            getnb[j] = p->str[k];
            --i;
            ++k;
            ++j;
        }
        my_float(va_arg(arg, double), my_getnbr(getnb), p);
    }
    free(getnb);
}

void my_float(double number, int posi, parse_t *p)
{
    long nb = 0;

    if (number < 0) {
        my_putchar('-');
        number = number * -1;
    }
    nb = number;
    my_putnbr_long(nb, p);
    if (posi > 0) {
        my_putchar('.');
        p->length += 1;
    }
    while (posi > 0) {
        p->length += 1;
        number = (number - nb) * 10;
        nb = number;
        my_putchar(nb + 48);
        posi--;
    }
}