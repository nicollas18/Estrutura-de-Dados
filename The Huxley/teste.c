#include <stdio.h>

int main()
{
    char n1 = '2', n2 = '4';
    int soma;

    soma = ((int)n1 % (int)'0') + ((int)n2 % (int)'0');


    printf("%d\n", soma);

    return 0;


}