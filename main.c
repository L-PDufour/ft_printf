#include <stdio.h>
#include "libftprintf.h"

int main()
{
    int resultat_printf;
    int resultat_ft_printf;

    char c = 'c'
    char s[] = "test";
 
    printf("c : %c, valeur : %d \n", c, printf("%c", c));
    ft_printf("c : %c, valeur : %d \n\n", c, ft_printf("%c", c));
    
    printf("str : %s, valeur : %d \n", s, printf("%s", s) );
    ft_printf("str : %s, valeur : %d \n\n", s, ft_printf("%s", s) );
    
    printf("str : %s, valeur : %d \n", s, printf("%s", s) );
    ft_printf("str : %s, valeur : %d \n\n", s, ft_printf("%s", s) );
    
    printf("str : %s, valeur : %d \n", s, printf("%s", s) );
    ft_printf("str : %s, valeur : %d \n\n", s, ft_printf("%s", s) );
    
    printf("str : %s, valeur : %d \n", s, printf("%s", s) );
    ft_printf("str : %s, valeur : %d \n\n", s, ft_printf("%s", s) );
    
    printf("str : %s, valeur : %d \n", s, printf("%s", s) );
    ft_printf("str : %s, valeur : %d \n\n", s, ft_printf("%s", s) );
    
    printf("str : %s, valeur : %d \n", s, printf("%s", s) );
    ft_printf("str : %s, valeur : %d \n\n", s, ft_printf("%s", s) );
    
    printf("str : %s, valeur : %d \n", s, printf("%s", s) );
    ft_printf("str : %s, valeur : %d \n\n", s, ft_printf("%s", s) );



    // printf(", the value returned by printf() is : %d", printf("%s", s));



    // printf(printf("voici les résultats de printf"));
    // resultat_printf = printf("retour printf");
    
    
    // resultat_ft_printf = ft_printf("retour printf");

    // printf("\n%i\n", resultat_ft_printf);
}