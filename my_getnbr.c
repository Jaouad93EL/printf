/*
** ETNA PROJECT, 16/01/2019 by elhorm_j
** my_getnbr.c
** File description:
**      [...]
*/

#include "my_printf.h"

int not_more_less(char *str)
{
    int i = 0;

    while (str[i] == '-' || str[i] == '+')
        i++;
    return (i);
}

int negative(char *str)
{
    int i = 0;
    int n = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            n = n * -1;
        i++;
    }
    return (n);
}

int my_pow(int n, int p)
{
    int a = 1;
    int save = n;

    if (p == 0)
        return (1);
    else if (p < 0)
        return (0);
    else
        while (a < p) {
            n = n * save;
            a = a + 1;
        }
    return (n);
}

int my_strlen(char *str)
{
    int compte = 0;

    while (str[compte] != '\0')
        compte = compte + 1;
    return (compte);
}

int my_getnbr(char *str)
{
    int i = my_strlen(str);
    int j = not_more_less(str);
    int p = 0;
    int save = 0;
    int nb = 0;

    while (i >= j) {
        if (str[i] >= '0' && str[i] <= '9') {
            save = str[i] - 48;
            nb = nb + (save * (my_pow(10, p)));
            p++;
        }
        else {
            nb = 0;
            p = 0;
        }
        i--;
    }
    return (nb * negative(str));
}