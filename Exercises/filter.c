#include <stdio.h>

int par(int x)
{
    if(x % 2 == 0) return 1;
    else return 0;
}

int filter(int (*f)(int), int x)
{
    int resultado;
    resultado = (*f)(x);

    if(resultado == 1) printf("%d É par!\n", x);
}

int main(){

    int tamanho;
    
    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    for(int i = 0; i < tamanho; i++)
    {
        printf("Digite o número do array: ");
        
        int num;
        scanf("%d", &num);
        array[i] = num;

        filter(par, array[i]);
    }

    return 0;
}