/*
** ETNA PROJECT, 16/01/2019 by elhorm_j
** my_printf.h
** File description:
**      [...]
*/

#ifndef LIBMY_MY_PRINTF_H
#define LIBMY_MY_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct parse_s {
    char *liste_flag;
    const char *str;
    void (*fun_tab[10])();
    int length;
    int index;
    int prec;
} parse_t;

void my_putchar(char c);
int not_more_less(char *str);
int negative(char *str);
int my_pow(int n, int p);
int my_strlen(char *str);
int my_getnbr(char *str);
void my_putstr(char *str, parse_t *p);
void my_putnbr(int n, parse_t *p);
void my_putnbr_hexa(unsigned int n, int c, parse_t *p);
void my_putnbr_octal(unsigned int n, parse_t *p);
void my_put_one(int c);
int my_printf(const char *arg, ...);
int flag_choice(va_list arg, parse_t *p);
void init_fun(parse_t *p);
void my_float(double nbFloat, int posi, parse_t *p);
void my_putnbr_long(long n, parse_t *p);
void my_putnbr_unsigned(unsigned int n, parse_t *p);
void my_print_nbr(va_list arg, parse_t *p);
void my_print_str(va_list arg, parse_t *p);
void my_print_char(va_list arg, parse_t *p);
void my_print_float(va_list arg, parse_t *p);
void my_print_octal(va_list arg, parse_t *p);
void my_print_hexa(va_list arg, int c, parse_t *p);
void my_print_unsigned(va_list arg, parse_t *p);
void my_print_prec(va_list arg, parse_t *p);

#endif //LIBMY_MY_PRINTF_H