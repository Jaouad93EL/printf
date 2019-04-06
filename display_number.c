/*
** ETNA PROJECT, 16/01/2019 by elhorm_j
** functionOne.c
** File description:
**      [...]
*/

#include "my_printf.h"

void my_putnbr(int n, parse_t *p)
{
    if (n < 0) {
        if (n == -2147483648) {
            my_putstr("-2147483648", p);
            return;
        }
        my_putchar('-');
        n *= -1;
    }
    if (n > 9) {
        my_putnbr(n / 10, p);
        my_putnbr(n % 10, p);
    } else {
        my_putchar(n + 48);
        p->length += 1;
    }
}

void my_putnbr_unsigned(unsigned int n, parse_t *p)
{
    if (n > 9) {
        my_putnbr_unsigned(n / 10, p);
        my_putnbr_unsigned(n % 10, p);
    } else {
        my_putchar(n + 48);
        p->length += 1;
    }
}

void my_putnbr_long(long n, parse_t *p)
{
    if (n < 0) {
        if (n == -2147483648) {
            my_putstr("-2147483648", p);
            return;
        }
        my_putchar('-');
        n *= -1;
    }
    if (n > 9) {
        my_putnbr(n / 10, p);
        my_putnbr(n % 10, p);
    } else {
        my_putchar(n + 48);
        p->length += 1;
    }
}

void my_putnbr_hexa(unsigned int n, int c, parse_t *p)
{
    int m = 0;

    if (c == 'X')
        m = 55;
    else
        m = 87;
    if (n > 16) {
        my_putnbr_hexa(n / 16, c, p);
        my_putnbr_hexa(n % 16, c, p);
    } else if (n > 9)
        my_putchar (n + m);
    else {
        my_putchar(n + 48);
        p->length += 1;
    }
}

void my_putnbr_octal(unsigned int n, parse_t *p)
{
    if (n > 8) {
        my_putnbr_octal(n / 8, p);
        my_putnbr_octal(n % 8, p);
    } else {
        my_putchar(n + 48);
        p->length += 1;
    }
}