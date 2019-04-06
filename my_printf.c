/*
** ETNA PROJECT, 16/01/2019 by elhorm_j
** my_printf.c
** File description:
**      [...]
*/

#include "my_printf.h"

int my_printf(const char *str, ...)
{
    parse_t p;
    va_list arg;

    p.liste_flag = "dscfouxXi.";
    p.str = str;
    p.length = 0;
    init_fun(&p);
    va_start(arg, str);
    for (p.index = 0; str[p.index] != '\0'; ++p.index) {
        if (str[p.index] == '%') {
            ++p.index;
            flag_choice(arg, &p);
        }
        else {
            my_putchar(str[p.index]);
            p.length += 1;
        }
    }
    va_end(arg);
    return (p.length);
}

void init_fun(parse_t *p)
{
    p->fun_tab[0] = my_print_nbr;
    p->fun_tab[1] = my_print_str;
    p->fun_tab[2] = my_print_char;
    p->fun_tab[3] = my_print_float;
    p->fun_tab[4] = my_print_octal;
    p->fun_tab[5] = my_print_unsigned;
    p->fun_tab[6] = my_print_hexa;
    p->fun_tab[7] = my_print_hexa;
    p->fun_tab[8] = my_print_nbr;
    p->fun_tab[9] = my_print_prec;
}

int flag_choice(va_list arg, parse_t *p)
{
    int i = 0;

    for (i = 0; p->liste_flag[i] != '\0'; ++i) {
        if (p->str[p->index] == p->liste_flag[i]) {
            if (p->liste_flag[i] == '.')
                p->fun_tab[i](arg, p);
            else if (p->liste_flag[i] == 'x' || p->liste_flag[i] == 'X')
                p->fun_tab[i](arg, p->liste_flag[i], p);
            else
                p->fun_tab[i](arg, p);
            return (1);
        }
    }
    if (p->str[p->index] == '%') {
        my_putchar('%');
        return (1);
    }
    return (0);
}