#include <stdio.h>
#include "libftprintf.h"

int main()
{
    int resultat_printf;
    int resultat_ft_printf;

    char st[] = "test";
 
    printf("str : %s, valeur : %d \n", st, printf("%s", st) );
    ft_printf("str : %s, valeur : %d \n", st, ft_printf("%s", st) );
    printf("str : %s, valeur : %d \n", st, printf("%s", st) );
    ft_printf("str : %s, valeur : %d \n", st, ft_printf("%s", st) );

    // printf(", the value returned by printf() is : %d", printf("%s", st));



    // printf(printf("voici les résultats de printf"));
    // resultat_printf = printf("retour printf");
    
    
    // resultat_ft_printf = ft_printf("retour printf");

    // printf("\n%i\n", resultat_ft_printf);
}