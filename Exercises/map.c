#include <stdio.h>

int square(int x)
{
    return x*x;
}

int main() {

    int tamanho;
    int (*map) (int);
    map = square;

    printf("Digite o tamanho do array: ");
    scanf("%d", &tamanho);

    int array[tamanho];

    printf("Digite os números do array:\n");

    for(int i = 0; i < tamanho; i++)
    { 
        int num;
        scanf("%d", &num);
        array[i] = num;
    }

    for (int i = 0; i < tamanho; i++)
    {
        printf("%d ", (*map)(array[i]));
    }

    printf("\n");
    
    return 0;
}