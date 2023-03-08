#include <stdio.h>
#include "libftprintf.h"
#include "ft_printf.c"

int main()
{
    char c = 'd';
    int i = 20000000;
    int *p = &i;
    unsigned int u = 4294967295;
    c = 'd';
    char s[] = "test";

    printf("char c : %c\n", c);
    ft_printf("char c : %c\n", c);

    printf("str : %s, valeur : %d \n", s, printf("%s", s) );
    ft_printf("str : %s, valeur : %d \n\n", s, ft_printf("%s", s) );
    
    printf("ptr : %p, valeur : %d \n", p, printf("%p", p) );
    ft_printf("ptr : %p, valeur : %d \n\n", p, ft_printf("%p", p) );

    printf("dec : %d, valeur : %d \n", i, printf("%d", i) );
    ft_printf("dec : %d, valeur : %d \n\n", i, ft_printf("%d", i) );
    
    printf("int : %i, valeur : %d \n", i, printf("%i", i) );
    ft_printf("int : %i, valeur : %d \n\n", i, ft_printf("%i", i) );

    printf("int : %u, valeur : %d \n", u, printf("%u", u) );
    ft_printf("int : %u, valeur : %d \n\n", u, ft_printf("%u", u) );
    
    printf("hex : %x, valeur : %d \n", i, printf("%x", i) );
    ft_printf("hex : %x, valeur : %d \n\n", i, ft_printf("%x", i) );

    printf("hex : %X, valeur : %d \n", i, printf("%X", i) );
    ft_printf("hex : %X, valeur : %d \n\n", i, ft_printf("%X", i) );
}