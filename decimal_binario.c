#include <stdio.h>

void binario(int n)
{
    int resto;
    resto = n % 2;

    if(n == 0)
    {
        printf("%d", resto);

    } else {

        n = n / 10;
        binario(n);
        printf("%d", resto);
    }
}

int main()
{
    int number;
    scanf("%d", &number);
    
    binario(number);
    printf("\n");

    return 0;
}