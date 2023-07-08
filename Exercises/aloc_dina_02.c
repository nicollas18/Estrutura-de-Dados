#include <stdio.h>
#include <stdlib.h>

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
        printf("%d ", v[i]);
    }

    printf("\n");

    free(v);

    return 0;
}