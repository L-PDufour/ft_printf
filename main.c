 #include <stdio.h>
 #include "ft_printf.h"
 #include "ft_printf.c"
 #include "utils.c"

 int main()
 {
     char c = 'd';
     int i = -2000000;
     int *p = &i;
     unsigned int u = -94967295;
     int result = 0;

     char s[] = "test";
   printf(" %p \n", -1);
   ft_printf(" %p  \n", -1);
/*
   ft_printf("%5%");
   printf("%d\n", result);
   result = ft_printf("lettre");
     ft_printf("%d\n", result);
     result = printf("lettre : %c ", c);
     printf("%d\n", result);
     result = ft_printf("lettre : %c ", c);
     ft_printf("%d\n", result);
     // // STR
     result = printf("str : %s ", s);
     printf("%d\n", result);
     result = ft_printf("str : %s ", s);
     ft_printf("%d\n", result);
     // // DEC
     result = printf("%d", i);
     printf("%d\n", result);
     result = ft_printf("%d", i);
     ft_printf("%d\n", result);
     result = printf("dec : %d %i %u", i, i, u);
     printf("%d\n", result);
     result = ft_printf("dec : %d %i %u", i, i, u);
     ft_printf("%d\n", result);
     // HEX
     result = printf("hex : %x %X %p", i, i, p);
     printf("%d\n", result);
     result = ft_printf("hex : %x %X %p", i, i, p);
     ft_printf("%d\n", result);*/
   return (0);
 }

