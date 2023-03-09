#include <stdio.h>
#include "libftprintf.h"
#include "ft_printf.c"

int main()
{
    char c = 'd';
    int i = -20000000;
    int *p = &i;
    unsigned int u = 294967295;
    int result = 0;

    char s[] = "test";
    // CHAR
    result = printf("le%%ttre : %c ", c);
    printf("%d\n", result);
    result = ft_printf("le%%ttre : %c ", c);
    ft_printf("%d\n", result);
    // STR
    result = printf("str : %s ", s);
    printf("%d\n", result);
    result = ft_printf("str : %s ", s);
    ft_printf("%d\n", result);
    // DEC
    result = printf("dec : %d %i %u ", i, i, u);
    printf("%d\n", result);
    result = ft_printf("dec : %d %i %u ", i, i, u);
    ft_printf("%d\n", result);
    // HEX
    result = printf("hex : %x %X %p ", i, i, p);
    printf("%d\n", result);
    result = ft_printf("hex : %x %X %p ", i, i, p);
    ft_printf("%d\n", result);
}