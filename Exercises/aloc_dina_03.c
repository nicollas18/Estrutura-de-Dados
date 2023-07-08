#include <stdio.h>
#include <stdlib.h>

/* Par ou impar com alocação dinâmica*/

int main() {

    int tamanho;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *v;

    v = (int*) malloc(tamanho * sizeof(int));

    for(int i = 0;  i < tamanho; i++)
    {
        int numero;

        printf("Digite um numero: ");
        scanf("%d", &numero);

        v[i] = numero;

    }

    for(int i = 0;  i < tamanho; i++)
    {
        if(v[i] %  2 == 0) printf("%d é par!\n", v[i]);
        else printf("%d é impar!\n", v[i]);
        
    }

    free(v);

    return 0;
}